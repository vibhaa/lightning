#! /usr/bin/python3
from pyln.proto.message import MessageNamespace, Message
import pytest


def test_fundamental():
    ns = MessageNamespace()
    ns.load_csv(['msgtype,test,1',
                 'msgdata,test,test_byte,byte,',
                 'msgdata,test,test_u16,u16,',
                 'msgdata,test,test_u32,u32,',
                 'msgdata,test,test_u64,u64,',
                 'msgdata,test,test_chain_hash,chain_hash,',
                 'msgdata,test,test_channel_id,channel_id,',
                 'msgdata,test,test_sha256,sha256,',
                 'msgdata,test,test_signature,signature,',
                 'msgdata,test,test_point,point,',
                 'msgdata,test,test_short_channel_id,short_channel_id,',
                 ])

    mstr = """test
 test_byte=255
 test_u16=65535
 test_u32=4294967295
 test_u64=18446744073709551615
 test_chain_hash=0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 test_channel_id=0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 test_sha256=0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 test_signature=0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f40
 test_point=0201030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f2021
 test_short_channel_id=1x2x3"""
    m = Message.from_str(ns, mstr)

    # Same (ignoring whitespace differences)
    assert m.to_str().split() == mstr.split()


def test_static_array():
    ns = MessageNamespace()
    ns.load_csv(['msgtype,test1,1',
                 'msgdata,test1,test_arr,byte,4'])
    ns.load_csv(['msgtype,test2,2',
                 'msgdata,test2,test_arr,short_channel_id,4'])

    for test in [["test1 test_arr=00010203", bytes([0, 1] + [0, 1, 2, 3])],
                 ["test2 test_arr=[0x1x2,4x5x6,7x8x9,10x11x12]",
                  bytes([0, 2]
                        + [0, 0, 0, 0, 0, 1, 0, 2]
                        + [0, 0, 4, 0, 0, 5, 0, 6]
                        + [0, 0, 7, 0, 0, 8, 0, 9]
                        + [0, 0, 10, 0, 0, 11, 0, 12])]]:
        m = Message.from_str(ns, test[0])
        assert m.to_str() == test[0]
        v = m.to_bin()
        assert v == test[1]
        assert Message.from_bin(ns, test[1]).to_str() == test[0]


def test_subtype():
    ns = MessageNamespace()
    ns.load_csv(['msgtype,test1,1',
                 'msgdata,test1,test_sub,channel_update_timestamps,4',
                 'subtype,channel_update_timestamps',
                 'subtypedata,'
                 + 'channel_update_timestamps,timestamp_node_id_1,u32,',
                 'subtypedata,'
                 + 'channel_update_timestamps,timestamp_node_id_2,u32,'])

    for test in [["test1 test_sub=["
                  "{timestamp_node_id_1=1,timestamp_node_id_2=2}"
                  ",{timestamp_node_id_1=3,timestamp_node_id_2=4}"
                  ",{timestamp_node_id_1=5,timestamp_node_id_2=6}"
                  ",{timestamp_node_id_1=7,timestamp_node_id_2=8}]",
                  bytes([0, 1]
                        + [0, 0, 0, 1, 0, 0, 0, 2]
                        + [0, 0, 0, 3, 0, 0, 0, 4]
                        + [0, 0, 0, 5, 0, 0, 0, 6]
                        + [0, 0, 0, 7, 0, 0, 0, 8])]]:
        m = Message.from_str(ns, test[0])
        assert m.to_str() == test[0]
        v = m.to_bin()
        assert v == test[1]
        assert Message.from_bin(ns, test[1]).to_str() == test[0]

    # Test missing field logic.
    m = Message.from_str(ns, "test1", incomplete_ok=True)
    assert m.missing_fields()


def test_tlv():
    ns = MessageNamespace()
    ns.load_csv(['msgtype,test1,1',
                 'msgdata,test1,tlvs,test_tlvstream,',
                 'tlvtype,test_tlvstream,tlv1,1',
                 'tlvdata,test_tlvstream,tlv1,field1,byte,4',
                 'tlvdata,test_tlvstream,tlv1,field2,u32,',
                 'tlvtype,test_tlvstream,tlv2,255',
                 'tlvdata,test_tlvstream,tlv2,field3,byte,...'])

    for test in [["test1 tlvs={tlv1={field1=01020304,field2=5}}",
                  bytes([0, 1]
                        + [1, 8, 1, 2, 3, 4, 0, 0, 0, 5])],
                 ["test1 tlvs={tlv1={field1=01020304,field2=5},tlv2={field3=01020304}}",
                  bytes([0, 1]
                        + [1, 8, 1, 2, 3, 4, 0, 0, 0, 5]
                        + [253, 0, 255, 4, 1, 2, 3, 4])],
                 ["test1 tlvs={tlv1={field1=01020304,field2=5},4=010203,tlv2={field3=01020304}}",
                  bytes([0, 1]
                        + [1, 8, 1, 2, 3, 4, 0, 0, 0, 5]
                        + [4, 3, 1, 2, 3]
                        + [253, 0, 255, 4, 1, 2, 3, 4])]]:
        m = Message.from_str(ns, test[0])
        assert m.to_str() == test[0]
        v = m.to_bin()
        assert v == test[1]
        assert Message.from_bin(ns, test[1]).to_str() == test[0]

    # Ordering test (turns into canonical ordering)
    m = Message.from_str(ns, 'test1 tlvs={tlv1={field1=01020304,field2=5},tlv2={field3=01020304},4=010203}')
    assert m.to_bin() == bytes([0, 1]
                               + [1, 8, 1, 2, 3, 4, 0, 0, 0, 5]
                               + [4, 3, 1, 2, 3]
                               + [253, 0, 255, 4, 1, 2, 3, 4])


def test_message_constructor():
    ns = MessageNamespace(['msgtype,test1,1',
                           'msgdata,test1,tlvs,test_tlvstream,',
                           'tlvtype,test_tlvstream,tlv1,1',
                           'tlvdata,test_tlvstream,tlv1,field1,byte,4',
                           'tlvdata,test_tlvstream,tlv1,field2,u32,',
                           'tlvtype,test_tlvstream,tlv2,255',
                           'tlvdata,test_tlvstream,tlv2,field3,byte,...'])

    m = Message(ns.get_msgtype('test1'),
                tlvs='{tlv1={field1=01020304,field2=5}'
                ',tlv2={field3=01020304},4=010203}')
    assert m.to_bin() == bytes([0, 1]
                               + [1, 8, 1, 2, 3, 4, 0, 0, 0, 5]
                               + [4, 3, 1, 2, 3]
                               + [253, 0, 255, 4, 1, 2, 3, 4])


def test_dynamic_array():
    """Test that dynamic array types enforce matching lengths"""
    ns = MessageNamespace(['msgtype,test1,1',
                           'msgdata,test1,count,u16,',
                           'msgdata,test1,arr1,byte,count',
                           'msgdata,test1,arr2,u32,count'])

    # This one is fine.
    m = Message(ns.get_msgtype('test1'),
                arr1='01020304', arr2='[1,2,3,4]')
    assert m.to_bin() == bytes([0, 1]
                               + [0, 4]
                               + [1, 2, 3, 4]
                               + [0, 0, 0, 1,
                                  0, 0, 0, 2,
                                  0, 0, 0, 3,
                                  0, 0, 0, 4])

    # These ones are not
    with pytest.raises(ValueError, match='Inconsistent length.*count'):
        m = Message(ns.get_msgtype('test1'),
                    arr1='01020304', arr2='[1,2,3]')

    with pytest.raises(ValueError, match='Inconsistent length.*count'):
        m = Message(ns.get_msgtype('test1'),
                    arr1='01020304', arr2='[1,2,3,4,5]')
