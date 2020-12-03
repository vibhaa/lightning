/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the .csv file it was generated from. */

#include "wire/onion_printgen.h"
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <common/utils.h>
#include <inttypes.h>
#include <stdio.h>

void printonion_wire_message(const u8 *msg)
{
	switch ((enum onion_wire)fromwire_peektype(msg)) {
		case WIRE_INVALID_REALM:
			printf("WIRE_INVALID_REALM:\n");
			printwire_invalid_realm("invalid_realm", msg);
			return;
		case WIRE_TEMPORARY_NODE_FAILURE:
			printf("WIRE_TEMPORARY_NODE_FAILURE:\n");
			printwire_temporary_node_failure("temporary_node_failure", msg);
			return;
		case WIRE_PERMANENT_NODE_FAILURE:
			printf("WIRE_PERMANENT_NODE_FAILURE:\n");
			printwire_permanent_node_failure("permanent_node_failure", msg);
			return;
		case WIRE_REQUIRED_NODE_FEATURE_MISSING:
			printf("WIRE_REQUIRED_NODE_FEATURE_MISSING:\n");
			printwire_required_node_feature_missing("required_node_feature_missing", msg);
			return;
		case WIRE_INVALID_ONION_VERSION:
			printf("WIRE_INVALID_ONION_VERSION:\n");
			printwire_invalid_onion_version("invalid_onion_version", msg);
			return;
		case WIRE_INVALID_ONION_HMAC:
			printf("WIRE_INVALID_ONION_HMAC:\n");
			printwire_invalid_onion_hmac("invalid_onion_hmac", msg);
			return;
		case WIRE_INVALID_ONION_KEY:
			printf("WIRE_INVALID_ONION_KEY:\n");
			printwire_invalid_onion_key("invalid_onion_key", msg);
			return;
		case WIRE_TEMPORARY_CHANNEL_FAILURE:
			printf("WIRE_TEMPORARY_CHANNEL_FAILURE:\n");
			printwire_temporary_channel_failure("temporary_channel_failure", msg);
			return;
		case WIRE_PERMANENT_CHANNEL_FAILURE:
			printf("WIRE_PERMANENT_CHANNEL_FAILURE:\n");
			printwire_permanent_channel_failure("permanent_channel_failure", msg);
			return;
		case WIRE_REQUIRED_CHANNEL_FEATURE_MISSING:
			printf("WIRE_REQUIRED_CHANNEL_FEATURE_MISSING:\n");
			printwire_required_channel_feature_missing("required_channel_feature_missing", msg);
			return;
		case WIRE_UNKNOWN_NEXT_PEER:
			printf("WIRE_UNKNOWN_NEXT_PEER:\n");
			printwire_unknown_next_peer("unknown_next_peer", msg);
			return;
		case WIRE_AMOUNT_BELOW_MINIMUM:
			printf("WIRE_AMOUNT_BELOW_MINIMUM:\n");
			printwire_amount_below_minimum("amount_below_minimum", msg);
			return;
		case WIRE_FEE_INSUFFICIENT:
			printf("WIRE_FEE_INSUFFICIENT:\n");
			printwire_fee_insufficient("fee_insufficient", msg);
			return;
		case WIRE_INCORRECT_CLTV_EXPIRY:
			printf("WIRE_INCORRECT_CLTV_EXPIRY:\n");
			printwire_incorrect_cltv_expiry("incorrect_cltv_expiry", msg);
			return;
		case WIRE_EXPIRY_TOO_SOON:
			printf("WIRE_EXPIRY_TOO_SOON:\n");
			printwire_expiry_too_soon("expiry_too_soon", msg);
			return;
		case WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS:
			printf("WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS:\n");
			printwire_incorrect_or_unknown_payment_details("incorrect_or_unknown_payment_details", msg);
			return;
		case WIRE_FINAL_INCORRECT_CLTV_EXPIRY:
			printf("WIRE_FINAL_INCORRECT_CLTV_EXPIRY:\n");
			printwire_final_incorrect_cltv_expiry("final_incorrect_cltv_expiry", msg);
			return;
		case WIRE_FINAL_INCORRECT_HTLC_AMOUNT:
			printf("WIRE_FINAL_INCORRECT_HTLC_AMOUNT:\n");
			printwire_final_incorrect_htlc_amount("final_incorrect_htlc_amount", msg);
			return;
		case WIRE_CHANNEL_DISABLED:
			printf("WIRE_CHANNEL_DISABLED:\n");
			printwire_channel_disabled("channel_disabled", msg);
			return;
		case WIRE_EXPIRY_TOO_FAR:
			printf("WIRE_EXPIRY_TOO_FAR:\n");
			printwire_expiry_too_far("expiry_too_far", msg);
			return;
		case WIRE_INVALID_ONION_PAYLOAD:
			printf("WIRE_INVALID_ONION_PAYLOAD:\n");
			printwire_invalid_onion_payload("invalid_onion_payload", msg);
			return;
		case WIRE_MPP_TIMEOUT:
			printf("WIRE_MPP_TIMEOUT:\n");
			printwire_mpp_timeout("mpp_timeout", msg);
			return;
	}

	printf("UNKNOWN: %s\\n", tal_hex(msg, msg));
}


static void printwire_tlv_tlv_payload_amt_to_forward(const char *fieldname, const u8 **cursor, size_t *plen)
{
	printf("(msg_name=%s)\n", "amt_to_forward");

	printf("amt_to_forward=");
	u64 amt_to_forward = fromwire_tu64(cursor, plen);

	printwire_u64(tal_fmt(NULL, "%s.amt_to_forward", fieldname), &amt_to_forward);
	if (!*cursor) {
		printf("**TRUNCATED**\n");
		return;
	}

}
static void printwire_tlv_tlv_payload_outgoing_cltv_value(const char *fieldname, const u8 **cursor, size_t *plen)
{
	printf("(msg_name=%s)\n", "outgoing_cltv_value");

	printf("outgoing_cltv_value=");
	u32 outgoing_cltv_value = fromwire_tu32(cursor, plen);

	printwire_u32(tal_fmt(NULL, "%s.outgoing_cltv_value", fieldname), &outgoing_cltv_value);
	if (!*cursor) {
		printf("**TRUNCATED**\n");
		return;
	}

}
static void printwire_tlv_tlv_payload_short_channel_id(const char *fieldname, const u8 **cursor, size_t *plen)
{
	printf("(msg_name=%s)\n", "short_channel_id");

	printf("short_channel_id=");
	struct short_channel_id short_channel_id;
	fromwire_short_channel_id(cursor, plen, &short_channel_id);

	printwire_short_channel_id(tal_fmt(NULL, "%s.short_channel_id", fieldname), &short_channel_id);
	if (!*cursor) {
		printf("**TRUNCATED**\n");
		return;
	}

}
static void printwire_tlv_tlv_payload_payment_data(const char *fieldname, const u8 **cursor, size_t *plen)
{
	printf("(msg_name=%s)\n", "payment_data");

	printf("payment_secret=");
	struct secret payment_secret;
	fromwire_secret(cursor, plen, &payment_secret);

	printwire_secret(tal_fmt(NULL, "%s.payment_secret", fieldname), &payment_secret);
	if (!*cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("total_msat=");
	u64 total_msat = fromwire_tu64(cursor, plen);

	printwire_u64(tal_fmt(NULL, "%s.total_msat", fieldname), &total_msat);
	if (!*cursor) {
		printf("**TRUNCATED**\n");
		return;
	}

}

static const struct tlv_print_record_type print_tlvs_tlv_payload[] = {
	{ 2, printwire_tlv_tlv_payload_amt_to_forward },
	{ 4, printwire_tlv_tlv_payload_outgoing_cltv_value },
	{ 6, printwire_tlv_tlv_payload_short_channel_id },
	{ 8, printwire_tlv_tlv_payload_payment_data },
};
void printwire_invalid_realm(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_REALM) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_temporary_node_failure(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_TEMPORARY_NODE_FAILURE) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_permanent_node_failure(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_PERMANENT_NODE_FAILURE) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_required_node_feature_missing(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_REQUIRED_NODE_FEATURE_MISSING) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_invalid_onion_version(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_VERSION) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("sha256_of_onion=");
	struct sha256 sha256_of_onion;
	fromwire_sha256(&cursor, &plen, &sha256_of_onion);

	printwire_sha256(tal_fmt(NULL, "%s.sha256_of_onion", fieldname), &sha256_of_onion);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_invalid_onion_hmac(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_HMAC) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("sha256_of_onion=");
	struct sha256 sha256_of_onion;
	fromwire_sha256(&cursor, &plen, &sha256_of_onion);

	printwire_sha256(tal_fmt(NULL, "%s.sha256_of_onion", fieldname), &sha256_of_onion);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_invalid_onion_key(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_KEY) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("sha256_of_onion=");
	struct sha256 sha256_of_onion;
	fromwire_sha256(&cursor, &plen, &sha256_of_onion);

	printwire_sha256(tal_fmt(NULL, "%s.sha256_of_onion", fieldname), &sha256_of_onion);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_temporary_channel_failure(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_TEMPORARY_CHANNEL_FAILURE) {
		printf("WRONG TYPE?!\n");
		return;
	}

	u16 len = fromwire_u16(&cursor, &plen);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("channel_update=");
	printwire_u8_array(tal_fmt(NULL, "%s.channel_update", fieldname), &cursor, &plen, len);

	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_permanent_channel_failure(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_PERMANENT_CHANNEL_FAILURE) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_required_channel_feature_missing(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_REQUIRED_CHANNEL_FEATURE_MISSING) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_unknown_next_peer(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_UNKNOWN_NEXT_PEER) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_amount_below_minimum(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_AMOUNT_BELOW_MINIMUM) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("htlc_msat=");
	struct amount_msat htlc_msat = fromwire_amount_msat(&cursor, &plen);

	printwire_amount_msat(tal_fmt(NULL, "%s.htlc_msat", fieldname), &htlc_msat);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	u16 len = fromwire_u16(&cursor, &plen);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("channel_update=");
	printwire_u8_array(tal_fmt(NULL, "%s.channel_update", fieldname), &cursor, &plen, len);

	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_fee_insufficient(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_FEE_INSUFFICIENT) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("htlc_msat=");
	struct amount_msat htlc_msat = fromwire_amount_msat(&cursor, &plen);

	printwire_amount_msat(tal_fmt(NULL, "%s.htlc_msat", fieldname), &htlc_msat);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	u16 len = fromwire_u16(&cursor, &plen);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("channel_update=");
	printwire_u8_array(tal_fmt(NULL, "%s.channel_update", fieldname), &cursor, &plen, len);

	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_incorrect_cltv_expiry(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INCORRECT_CLTV_EXPIRY) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("cltv_expiry=");
	u32 cltv_expiry = fromwire_u32(&cursor, &plen);

	printwire_u32(tal_fmt(NULL, "%s.cltv_expiry", fieldname), &cltv_expiry);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	u16 len = fromwire_u16(&cursor, &plen);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("channel_update=");
	printwire_u8_array(tal_fmt(NULL, "%s.channel_update", fieldname), &cursor, &plen, len);

	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_expiry_too_soon(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_EXPIRY_TOO_SOON) {
		printf("WRONG TYPE?!\n");
		return;
	}

	u16 len = fromwire_u16(&cursor, &plen);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("channel_update=");
	printwire_u8_array(tal_fmt(NULL, "%s.channel_update", fieldname), &cursor, &plen, len);

	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_incorrect_or_unknown_payment_details(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INCORRECT_OR_UNKNOWN_PAYMENT_DETAILS) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("htlc_msat=");
	struct amount_msat htlc_msat = fromwire_amount_msat(&cursor, &plen);

	printwire_amount_msat(tal_fmt(NULL, "%s.htlc_msat", fieldname), &htlc_msat);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("height=");
	u32 height = fromwire_u32(&cursor, &plen);

	printwire_u32(tal_fmt(NULL, "%s.height", fieldname), &height);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_final_incorrect_cltv_expiry(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_FINAL_INCORRECT_CLTV_EXPIRY) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("cltv_expiry=");
	u32 cltv_expiry = fromwire_u32(&cursor, &plen);

	printwire_u32(tal_fmt(NULL, "%s.cltv_expiry", fieldname), &cltv_expiry);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_final_incorrect_htlc_amount(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_FINAL_INCORRECT_HTLC_AMOUNT) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("incoming_htlc_amt=");
	struct amount_msat incoming_htlc_amt = fromwire_amount_msat(&cursor, &plen);

	printwire_amount_msat(tal_fmt(NULL, "%s.incoming_htlc_amt", fieldname), &incoming_htlc_amt);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_channel_disabled(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_CHANNEL_DISABLED) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_expiry_too_far(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_EXPIRY_TOO_FAR) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_invalid_onion_payload(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_INVALID_ONION_PAYLOAD) {
		printf("WRONG TYPE?!\n");
		return;
	}

	printf("type=");
	bigsize type = fromwire_bigsize(&cursor, &plen);

	printwire_bigsize(tal_fmt(NULL, "%s.type", fieldname), &type);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}
 	printf("offset=");
	u16 offset = fromwire_u16(&cursor, &plen);

	printwire_u16(tal_fmt(NULL, "%s.offset", fieldname), &offset);
	if (!cursor) {
		printf("**TRUNCATED**\n");
		return;
	}


	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}
void printwire_mpp_timeout(const char *fieldname, const u8 *cursor)
{

	size_t plen = tal_count(cursor);
	if (fromwire_u16(&cursor, &plen) != WIRE_MPP_TIMEOUT) {
		printf("WRONG TYPE?!\n");
		return;
	}



	if (plen != 0)
		printf("EXTRA: %s\n", tal_hexstr(NULL, cursor, plen));
}

void printonion_wire_tlv_message(const char *tlv_name, const u8 *msg) {
	size_t plen = tal_count(msg);
	if (strcmp(tlv_name, "tlv_payload") == 0) {
		printwire_tlvs(tlv_name, &msg, &plen, print_tlvs_tlv_payload, ARRAY_SIZE(print_tlvs_tlv_payload));
	}
}
// SHA256STAMP:3edc0ac5906e013377cc195c01e5cb67274c2a7560f51b946ff5149d755d36bd
