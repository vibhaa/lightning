/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H
#define LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <common/cryptomsg.h>
#include <common/features.h>
#include <common/wireaddr.h>
#include <wire/onion_wire.h>
#include <lightningd/gossip_msg.h>
#include <common/bolt11.h>

enum gossipd_wire {
        /*  Initialize the gossip daemon. */
        WIRE_GOSSIPD_INIT = 3000,
        /*  In developer mode */
        WIRE_GOSSIPD_DEV_SET_TIME = 3001,
        /*  Pass JSON-RPC getnodes call through */
        WIRE_GOSSIPD_GETNODES_REQUEST = 3005,
        WIRE_GOSSIPD_GETNODES_REPLY = 3105,
        /*  Pass JSON-RPC getroute call through */
        WIRE_GOSSIPD_GETROUTE_REQUEST = 3006,
        WIRE_GOSSIPD_GETROUTE_REPLY = 3106,
        WIRE_GOSSIPD_GETCHANNELS_REQUEST = 3007,
        WIRE_GOSSIPD_GETCHANNELS_REPLY = 3107,
        /*  Ping/pong test.  Waits for a reply if it expects one. */
        WIRE_GOSSIPD_PING = 3008,
        WIRE_GOSSIPD_PING_REPLY = 3108,
        /*  Set artificial maximum reply_channel_range size.  Master->gossipd */
        WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE = 3030,
        /*  Given a short_channel_id */
        WIRE_GOSSIPD_GET_STRIPPED_CUPDATE = 3010,
        WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY = 3110,
        /*  gossipd->master: we're closing this channel. */
        WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE = 3027,
        /*  Gossipd->master get this tx output please. */
        WIRE_GOSSIPD_GET_TXOUT = 3018,
        /*  master->gossipd here is the output */
        WIRE_GOSSIPD_GET_TXOUT_REPLY = 3118,
        /*  master->gossipd an htlc failed with this onion error. */
        WIRE_GOSSIPD_PAYMENT_FAILURE = 3021,
        /*  master -> gossipd: a potential funding outpoint was spent */
        WIRE_GOSSIPD_OUTPOINT_SPENT = 3024,
        /*  master -> gossipd: stop gossip timers. */
        WIRE_GOSSIPD_DEV_SUPPRESS = 3032,
        /*  master -> gossipd: do you have a memleak? */
        WIRE_GOSSIPD_DEV_MEMLEAK = 3033,
        WIRE_GOSSIPD_DEV_MEMLEAK_REPLY = 3133,
        /*  master -> gossipd: please rewrite the gossip_store */
        WIRE_GOSSIPD_DEV_COMPACT_STORE = 3034,
        /*  gossipd -> master: ok */
        WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY = 3134,
        /*  master -> gossipd: get route_info for our incoming channels */
        WIRE_GOSSIPD_GET_INCOMING_CHANNELS = 3025,
        /*  gossipd -> master: here they are. */
        WIRE_GOSSIPD_GET_INCOMING_CHANNELS_REPLY = 3125,
        /*  master -> gossipd: blockheight increased. */
        WIRE_GOSSIPD_NEW_BLOCKHEIGHT = 3026,
};

const char *gossipd_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool gossipd_wire_is_defined(u16 type);


/* WIRE: GOSSIPD_INIT */
/*  Initialize the gossip daemon. */
u8 *towire_gossipd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct feature_set *our_features, const struct node_id *id, const u8 rgb[3], const u8 alias[32], const struct wireaddr *announcable, u32 *dev_gossip_time, bool dev_fast_gossip, bool dev_fast_gossip_prune);
bool fromwire_gossipd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct feature_set **our_features, struct node_id *id, u8 rgb[3], u8 alias[32], struct wireaddr **announcable, u32 **dev_gossip_time, bool *dev_fast_gossip, bool *dev_fast_gossip_prune);

/* WIRE: GOSSIPD_DEV_SET_TIME */
/*  In developer mode */
u8 *towire_gossipd_dev_set_time(const tal_t *ctx, u32 dev_gossip_time);
bool fromwire_gossipd_dev_set_time(const void *p, u32 *dev_gossip_time);

/* WIRE: GOSSIPD_GETNODES_REQUEST */
/*  Pass JSON-RPC getnodes call through */
u8 *towire_gossipd_getnodes_request(const tal_t *ctx, const struct node_id *id);
bool fromwire_gossipd_getnodes_request(const tal_t *ctx, const void *p, struct node_id **id);

/* WIRE: GOSSIPD_GETNODES_REPLY */
u8 *towire_gossipd_getnodes_reply(const tal_t *ctx, const struct gossip_getnodes_entry **nodes);
bool fromwire_gossipd_getnodes_reply(const tal_t *ctx, const void *p, struct gossip_getnodes_entry ***nodes);

/* WIRE: GOSSIPD_GETROUTE_REQUEST */
/*  Pass JSON-RPC getroute call through */
u8 *towire_gossipd_getroute_request(const tal_t *ctx, const struct node_id *source, const struct node_id *destination, struct amount_msat msatoshi, u64 riskfactor_millionths, u32 final_cltv, u64 fuzz_millionths, const struct exclude_entry **excluded, u32 max_hops);
bool fromwire_gossipd_getroute_request(const tal_t *ctx, const void *p, struct node_id **source, struct node_id *destination, struct amount_msat *msatoshi, u64 *riskfactor_millionths, u32 *final_cltv, u64 *fuzz_millionths, struct exclude_entry ***excluded, u32 *max_hops);

/* WIRE: GOSSIPD_GETROUTE_REPLY */
u8 *towire_gossipd_getroute_reply(const tal_t *ctx, const struct route_hop **hops);
bool fromwire_gossipd_getroute_reply(const tal_t *ctx, const void *p, struct route_hop ***hops);

/* WIRE: GOSSIPD_GETCHANNELS_REQUEST */
u8 *towire_gossipd_getchannels_request(const tal_t *ctx, const struct short_channel_id *short_channel_id, const struct node_id *source, const struct short_channel_id *prev);
bool fromwire_gossipd_getchannels_request(const tal_t *ctx, const void *p, struct short_channel_id **short_channel_id, struct node_id **source, struct short_channel_id **prev);

/* WIRE: GOSSIPD_GETCHANNELS_REPLY */
u8 *towire_gossipd_getchannels_reply(const tal_t *ctx, bool complete, const struct gossip_getchannels_entry **nodes);
bool fromwire_gossipd_getchannels_reply(const tal_t *ctx, const void *p, bool *complete, struct gossip_getchannels_entry ***nodes);

/* WIRE: GOSSIPD_PING */
/*  Ping/pong test.  Waits for a reply if it expects one. */
u8 *towire_gossipd_ping(const tal_t *ctx, const struct node_id *id, u16 num_pong_bytes, u16 len);
bool fromwire_gossipd_ping(const void *p, struct node_id *id, u16 *num_pong_bytes, u16 *len);

/* WIRE: GOSSIPD_PING_REPLY */
u8 *towire_gossipd_ping_reply(const tal_t *ctx, const struct node_id *id, bool sent, u16 totlen);
bool fromwire_gossipd_ping_reply(const void *p, struct node_id *id, bool *sent, u16 *totlen);

/* WIRE: GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE */
/*  Set artificial maximum reply_channel_range size.  Master->gossipd */
u8 *towire_gossipd_dev_set_max_scids_encode_size(const tal_t *ctx, u32 max);
bool fromwire_gossipd_dev_set_max_scids_encode_size(const void *p, u32 *max);

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE */
/*  Given a short_channel_id */
u8 *towire_gossipd_get_stripped_cupdate(const tal_t *ctx, const struct short_channel_id *channel_id);
bool fromwire_gossipd_get_stripped_cupdate(const void *p, struct short_channel_id *channel_id);

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE_REPLY */
u8 *towire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const u8 *stripped_update);
bool fromwire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const void *p, u8 **stripped_update);

/* WIRE: GOSSIPD_LOCAL_CHANNEL_CLOSE */
/*  gossipd->master: we're closing this channel. */
u8 *towire_gossipd_local_channel_close(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_local_channel_close(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_GET_TXOUT */
/*  Gossipd->master get this tx output please. */
u8 *towire_gossipd_get_txout(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_get_txout(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_GET_TXOUT_REPLY */
/*  master->gossipd here is the output */
u8 *towire_gossipd_get_txout_reply(const tal_t *ctx, const struct short_channel_id *short_channel_id, struct amount_sat satoshis, const u8 *outscript);
bool fromwire_gossipd_get_txout_reply(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct amount_sat *satoshis, u8 **outscript);

/* WIRE: GOSSIPD_PAYMENT_FAILURE */
/*  master->gossipd an htlc failed with this onion error. */
u8 *towire_gossipd_payment_failure(const tal_t *ctx, const u8 *error);
bool fromwire_gossipd_payment_failure(const tal_t *ctx, const void *p, u8 **error);

/* WIRE: GOSSIPD_OUTPOINT_SPENT */
/*  master -> gossipd: a potential funding outpoint was spent */
u8 *towire_gossipd_outpoint_spent(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_outpoint_spent(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_DEV_SUPPRESS */
/*  master -> gossipd: stop gossip timers. */
u8 *towire_gossipd_dev_suppress(const tal_t *ctx);
bool fromwire_gossipd_dev_suppress(const void *p);

/* WIRE: GOSSIPD_DEV_MEMLEAK */
/*  master -> gossipd: do you have a memleak? */
u8 *towire_gossipd_dev_memleak(const tal_t *ctx);
bool fromwire_gossipd_dev_memleak(const void *p);

/* WIRE: GOSSIPD_DEV_MEMLEAK_REPLY */
u8 *towire_gossipd_dev_memleak_reply(const tal_t *ctx, bool leak);
bool fromwire_gossipd_dev_memleak_reply(const void *p, bool *leak);

/* WIRE: GOSSIPD_DEV_COMPACT_STORE */
/*  master -> gossipd: please rewrite the gossip_store */
u8 *towire_gossipd_dev_compact_store(const tal_t *ctx);
bool fromwire_gossipd_dev_compact_store(const void *p);

/* WIRE: GOSSIPD_DEV_COMPACT_STORE_REPLY */
/*  gossipd -> master: ok */
u8 *towire_gossipd_dev_compact_store_reply(const tal_t *ctx, bool success);
bool fromwire_gossipd_dev_compact_store_reply(const void *p, bool *success);

/* WIRE: GOSSIPD_GET_INCOMING_CHANNELS */
/*  master -> gossipd: get route_info for our incoming channels */
u8 *towire_gossipd_get_incoming_channels(const tal_t *ctx);
bool fromwire_gossipd_get_incoming_channels(const void *p);

/* WIRE: GOSSIPD_GET_INCOMING_CHANNELS_REPLY */
/*  gossipd -> master: here they are. */
u8 *towire_gossipd_get_incoming_channels_reply(const tal_t *ctx, const struct route_info *public_route_info, const bool *public_deadends, const struct route_info *private_route_info, const bool *private_deadends);
bool fromwire_gossipd_get_incoming_channels_reply(const tal_t *ctx, const void *p, struct route_info **public_route_info, bool **public_deadends, struct route_info **private_route_info, bool **private_deadends);

/* WIRE: GOSSIPD_NEW_BLOCKHEIGHT */
/*  master -> gossipd: blockheight increased. */
u8 *towire_gossipd_new_blockheight(const tal_t *ctx, u32 blockheight);
bool fromwire_gossipd_new_blockheight(const void *p, u32 *blockheight);


#endif /* LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H */
// SHA256STAMP:a494fd8a3f5ae31d113f387445744dd19490149be92d83f9bf61cc952457ad8f
