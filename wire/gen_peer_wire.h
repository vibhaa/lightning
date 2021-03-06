/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_WIRE_GEN_PEER_WIRE_H
#define LIGHTNING_WIRE_GEN_PEER_WIRE_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>

enum wire_type {
        WIRE_INIT = 16,
        WIRE_ERROR = 17,
        WIRE_PING = 18,
        WIRE_PONG = 19,
        WIRE_OPEN_CHANNEL = 32,
        WIRE_ACCEPT_CHANNEL = 33,
        WIRE_FUNDING_CREATED = 34,
        WIRE_FUNDING_SIGNED = 35,
        WIRE_FUNDING_LOCKED = 36,
        WIRE_SHUTDOWN = 38,
        WIRE_CLOSING_SIGNED = 39,
        WIRE_UPDATE_ADD_HTLC = 128,
        WIRE_UPDATE_FULFILL_HTLC = 130,
        WIRE_UPDATE_FAIL_HTLC = 131,
        WIRE_UPDATE_FAIL_MALFORMED_HTLC = 135,
        WIRE_COMMITMENT_SIGNED = 132,
        WIRE_REVOKE_AND_ACK = 133,
        WIRE_UPDATE_FEE = 134,
        WIRE_CHANNEL_REESTABLISH = 136,
        WIRE_ANNOUNCEMENT_SIGNATURES = 259,
        WIRE_CHANNEL_ANNOUNCEMENT = 256,
        WIRE_NODE_ANNOUNCEMENT = 257,
        WIRE_CHANNEL_UPDATE = 258,
        WIRE_QUERY_SHORT_CHANNEL_IDS = 261,
        WIRE_REPLY_SHORT_CHANNEL_IDS_END = 262,
        WIRE_QUERY_CHANNEL_RANGE = 263,
        WIRE_REPLY_CHANNEL_RANGE = 264,
        WIRE_GOSSIP_TIMESTAMP_FILTER = 265,
};

const char *wire_type_name(int e);

struct channel_update_checksums {
        u32 checksum_node_id_1;
        u32 checksum_node_id_2;
};
struct channel_update_timestamps {
        u32 timestamp_node_id_1;
        u32 timestamp_node_id_2;
};
struct tlv_init_tlvs_networks {
        struct bitcoin_blkid *chains;
};
struct tlv_n1_tlv1 {
        u64 amount_msat;
};
struct tlv_n1_tlv2 {
        struct short_channel_id scid;
};
struct tlv_n1_tlv3 {
        struct pubkey node_id;
        struct amount_msat amount_msat_1;
        struct amount_msat amount_msat_2;
};
struct tlv_n1_tlv4 {
        u16 cltv_delta;
};
struct tlv_n2_tlv1 {
        u64 amount_msat;
};
struct tlv_n2_tlv2 {
        u32 cltv_expiry;
};
struct tlv_query_short_channel_ids_tlvs_query_flags {
        u8 encoding_type;
        u8 *encoded_query_flags;
};
struct tlv_query_channel_range_tlvs_query_option {
        varint query_option_flags;
};
struct tlv_reply_channel_range_tlvs_timestamps_tlv {
        u8 encoding_type;
        u8 *encoded_timestamps;
};
struct tlv_reply_channel_range_tlvs_checksums_tlv {
        struct channel_update_checksums *checksums;
};
struct tlv_init_tlvs {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_init_tlvs_networks *networks;
};
struct tlv_n1 {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_n1_tlv1 *tlv1;
        struct tlv_n1_tlv2 *tlv2;
        struct tlv_n1_tlv3 *tlv3;
        struct tlv_n1_tlv4 *tlv4;
};
struct tlv_n2 {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_n2_tlv1 *tlv1;
        struct tlv_n2_tlv2 *tlv2;
};
struct tlv_query_short_channel_ids_tlvs {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_query_short_channel_ids_tlvs_query_flags *query_flags;
};
struct tlv_query_channel_range_tlvs {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_query_channel_range_tlvs_query_option *query_option;
};
struct tlv_reply_channel_range_tlvs {
        /* Raw fields including unknown ones. */
        struct tlv_field *fields;

	/* TODO The following explicit fields could just point into the
	 * tlv_field entries above to save on memory. */
        struct tlv_reply_channel_range_tlvs_timestamps_tlv *timestamps_tlv;
        struct tlv_reply_channel_range_tlvs_checksums_tlv *checksums_tlv;
};

struct tlv_init_tlvs *tlv_init_tlvs_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the init_tlvs namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using init_tlvs_is_valid.
 */
bool fromwire_init_tlvs(const u8 **cursor, size_t *max,
			  struct tlv_init_tlvs * record);

/**
 * Serialize a TLV stream for the init_tlvs namespace.
 *
 * This function only considers known fields from the init_tlvs namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `init_tlvs_is_valid`.
 */
void towire_init_tlvs(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool init_tlvs_is_valid(const struct tlv_init_tlvs *record,
			  size_t *err_index);

struct tlv_n1 *tlv_n1_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the n1 namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using n1_is_valid.
 */
bool fromwire_n1(const u8 **cursor, size_t *max,
			  struct tlv_n1 * record);

/**
 * Serialize a TLV stream for the n1 namespace.
 *
 * This function only considers known fields from the n1 namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `n1_is_valid`.
 */
void towire_n1(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool n1_is_valid(const struct tlv_n1 *record,
			  size_t *err_index);

#define TLVS_N1_ARRAY_SIZE 4
extern const struct tlv_record_type tlvs_n1[];

struct tlv_n2 *tlv_n2_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the n2 namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using n2_is_valid.
 */
bool fromwire_n2(const u8 **cursor, size_t *max,
			  struct tlv_n2 * record);

/**
 * Serialize a TLV stream for the n2 namespace.
 *
 * This function only considers known fields from the n2 namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `n2_is_valid`.
 */
void towire_n2(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool n2_is_valid(const struct tlv_n2 *record,
			  size_t *err_index);

#define TLVS_N2_ARRAY_SIZE 2
extern const struct tlv_record_type tlvs_n2[];

struct tlv_query_short_channel_ids_tlvs *tlv_query_short_channel_ids_tlvs_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the query_short_channel_ids_tlvs namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using query_short_channel_ids_tlvs_is_valid.
 */
bool fromwire_query_short_channel_ids_tlvs(const u8 **cursor, size_t *max,
			  struct tlv_query_short_channel_ids_tlvs * record);

/**
 * Serialize a TLV stream for the query_short_channel_ids_tlvs namespace.
 *
 * This function only considers known fields from the query_short_channel_ids_tlvs namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `query_short_channel_ids_tlvs_is_valid`.
 */
void towire_query_short_channel_ids_tlvs(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool query_short_channel_ids_tlvs_is_valid(const struct tlv_query_short_channel_ids_tlvs *record,
			  size_t *err_index);

struct tlv_query_channel_range_tlvs *tlv_query_channel_range_tlvs_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the query_channel_range_tlvs namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using query_channel_range_tlvs_is_valid.
 */
bool fromwire_query_channel_range_tlvs(const u8 **cursor, size_t *max,
			  struct tlv_query_channel_range_tlvs * record);

/**
 * Serialize a TLV stream for the query_channel_range_tlvs namespace.
 *
 * This function only considers known fields from the query_channel_range_tlvs namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `query_channel_range_tlvs_is_valid`.
 */
void towire_query_channel_range_tlvs(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool query_channel_range_tlvs_is_valid(const struct tlv_query_channel_range_tlvs *record,
			  size_t *err_index);

struct tlv_reply_channel_range_tlvs *tlv_reply_channel_range_tlvs_new(const tal_t *ctx);

/**
 * Deserialize a TLV stream for the reply_channel_range_tlvs namespace.
 *
 * This function will parse any TLV stream, as long as the type, length and
 * value fields are formatted correctly. Fields that are not known in the
 * current namespace are stored in the `fields` member. Validity can be
 * checked using reply_channel_range_tlvs_is_valid.
 */
bool fromwire_reply_channel_range_tlvs(const u8 **cursor, size_t *max,
			  struct tlv_reply_channel_range_tlvs * record);

/**
 * Serialize a TLV stream for the reply_channel_range_tlvs namespace.
 *
 * This function only considers known fields from the reply_channel_range_tlvs namespace,
 * and will ignore any fields that may be stored in the `fields` member. This
 * ensures that the resulting stream is valid according to
 * `reply_channel_range_tlvs_is_valid`.
 */
void towire_reply_channel_range_tlvs(u8 **pptr, const void *record);

/**
 * Check that the TLV stream is valid.
 *
 * Enforces the followin validity rules:
 * - Types must be in monotonic non-repeating order
 * - We must understand all even types
 *
 * Returns false if an error was detected, otherwise returns true. If err_index
 * is non-null and we detect an error it is set to the index of the first error
 * detected.
 */
bool reply_channel_range_tlvs_is_valid(const struct tlv_reply_channel_range_tlvs *record,
			  size_t *err_index);

/* SUBTYPE: CHANNEL_UPDATE_CHECKSUMS */
void towire_channel_update_checksums(u8 **p, const struct channel_update_checksums *channel_update_checksums);
void fromwire_channel_update_checksums(const u8 **cursor, size_t *plen, struct channel_update_checksums *channel_update_checksums);

/* SUBTYPE: CHANNEL_UPDATE_TIMESTAMPS */
void towire_channel_update_timestamps(u8 **p, const struct channel_update_timestamps *channel_update_timestamps);
void fromwire_channel_update_timestamps(const u8 **cursor, size_t *plen, struct channel_update_timestamps *channel_update_timestamps);

/* WIRE: INIT */
u8 *towire_init(const tal_t *ctx, const u8 *globalfeatures, const u8 *localfeatures, const struct tlv_init_tlvs *tlvs);
bool fromwire_init(const tal_t *ctx, const void *p, u8 **globalfeatures, u8 **localfeatures, struct tlv_init_tlvs *tlvs);

/* WIRE: ERROR */
u8 *towire_error(const tal_t *ctx, const struct channel_id *channel_id, const u8 *data);
bool fromwire_error(const tal_t *ctx, const void *p, struct channel_id *channel_id, u8 **data);

/* WIRE: PING */
u8 *towire_ping(const tal_t *ctx, u16 num_pong_bytes, const u8 *ignored);
bool fromwire_ping(const tal_t *ctx, const void *p, u16 *num_pong_bytes, u8 **ignored);

/* WIRE: PONG */
u8 *towire_pong(const tal_t *ctx, const u8 *ignored);
bool fromwire_pong(const tal_t *ctx, const void *p, u8 **ignored);

/* WIRE: OPEN_CHANNEL */
u8 *towire_open_channel(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, const struct channel_id *temporary_channel_id, struct amount_sat funding_satoshis, struct amount_msat push_msat, struct amount_sat dust_limit_satoshis, struct amount_msat max_htlc_value_in_flight_msat, struct amount_sat channel_reserve_satoshis, struct amount_msat htlc_minimum_msat, u32 feerate_per_kw, u16 to_self_delay, u16 max_accepted_htlcs, const struct pubkey *funding_pubkey, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *first_per_commitment_point, u8 channel_flags);
bool fromwire_open_channel(const void *p, struct bitcoin_blkid *chain_hash, struct channel_id *temporary_channel_id, struct amount_sat *funding_satoshis, struct amount_msat *push_msat, struct amount_sat *dust_limit_satoshis, struct amount_msat *max_htlc_value_in_flight_msat, struct amount_sat *channel_reserve_satoshis, struct amount_msat *htlc_minimum_msat, u32 *feerate_per_kw, u16 *to_self_delay, u16 *max_accepted_htlcs, struct pubkey *funding_pubkey, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *first_per_commitment_point, u8 *channel_flags);

/* WIRE: ACCEPT_CHANNEL */
u8 *towire_accept_channel(const tal_t *ctx, const struct channel_id *temporary_channel_id, struct amount_sat dust_limit_satoshis, struct amount_msat max_htlc_value_in_flight_msat, struct amount_sat channel_reserve_satoshis, struct amount_msat htlc_minimum_msat, u32 minimum_depth, u16 to_self_delay, u16 max_accepted_htlcs, const struct pubkey *funding_pubkey, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *first_per_commitment_point);
bool fromwire_accept_channel(const void *p, struct channel_id *temporary_channel_id, struct amount_sat *dust_limit_satoshis, struct amount_msat *max_htlc_value_in_flight_msat, struct amount_sat *channel_reserve_satoshis, struct amount_msat *htlc_minimum_msat, u32 *minimum_depth, u16 *to_self_delay, u16 *max_accepted_htlcs, struct pubkey *funding_pubkey, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *first_per_commitment_point);

/* WIRE: FUNDING_CREATED */
u8 *towire_funding_created(const tal_t *ctx, const struct channel_id *temporary_channel_id, const struct bitcoin_txid *funding_txid, u16 funding_output_index, const secp256k1_ecdsa_signature *signature);
bool fromwire_funding_created(const void *p, struct channel_id *temporary_channel_id, struct bitcoin_txid *funding_txid, u16 *funding_output_index, secp256k1_ecdsa_signature *signature);

/* WIRE: FUNDING_SIGNED */
u8 *towire_funding_signed(const tal_t *ctx, const struct channel_id *channel_id, const secp256k1_ecdsa_signature *signature);
bool fromwire_funding_signed(const void *p, struct channel_id *channel_id, secp256k1_ecdsa_signature *signature);

/* WIRE: FUNDING_LOCKED */
u8 *towire_funding_locked(const tal_t *ctx, const struct channel_id *channel_id, const struct pubkey *next_per_commitment_point);
bool fromwire_funding_locked(const void *p, struct channel_id *channel_id, struct pubkey *next_per_commitment_point);

/* WIRE: SHUTDOWN */
u8 *towire_shutdown(const tal_t *ctx, const struct channel_id *channel_id, const u8 *scriptpubkey);
bool fromwire_shutdown(const tal_t *ctx, const void *p, struct channel_id *channel_id, u8 **scriptpubkey);

/* WIRE: CLOSING_SIGNED */
u8 *towire_closing_signed(const tal_t *ctx, const struct channel_id *channel_id, struct amount_sat fee_satoshis, const secp256k1_ecdsa_signature *signature);
bool fromwire_closing_signed(const void *p, struct channel_id *channel_id, struct amount_sat *fee_satoshis, secp256k1_ecdsa_signature *signature);

/* WIRE: UPDATE_ADD_HTLC */
u8 *towire_update_add_htlc(const tal_t *ctx, const struct channel_id *channel_id, u64 id, struct amount_msat amount_msat, const struct sha256 *payment_hash, u32 cltv_expiry, const u8 onion_routing_packet[1366]);
bool fromwire_update_add_htlc(const void *p, struct channel_id *channel_id, u64 *id, struct amount_msat *amount_msat, struct sha256 *payment_hash, u32 *cltv_expiry, u8 onion_routing_packet[1366]);

/* WIRE: UPDATE_FULFILL_HTLC */
u8 *towire_update_fulfill_htlc(const tal_t *ctx, const struct channel_id *channel_id, u64 id, const struct preimage *payment_preimage);
bool fromwire_update_fulfill_htlc(const void *p, struct channel_id *channel_id, u64 *id, struct preimage *payment_preimage);

/* WIRE: UPDATE_FAIL_HTLC */
u8 *towire_update_fail_htlc(const tal_t *ctx, const struct channel_id *channel_id, u64 id, const u8 *reason);
bool fromwire_update_fail_htlc(const tal_t *ctx, const void *p, struct channel_id *channel_id, u64 *id, u8 **reason);

/* WIRE: UPDATE_FAIL_MALFORMED_HTLC */
u8 *towire_update_fail_malformed_htlc(const tal_t *ctx, const struct channel_id *channel_id, u64 id, const struct sha256 *sha256_of_onion, u16 failure_code);
bool fromwire_update_fail_malformed_htlc(const void *p, struct channel_id *channel_id, u64 *id, struct sha256 *sha256_of_onion, u16 *failure_code);

/* WIRE: COMMITMENT_SIGNED */
u8 *towire_commitment_signed(const tal_t *ctx, const struct channel_id *channel_id, const secp256k1_ecdsa_signature *signature, const secp256k1_ecdsa_signature *htlc_signature);
bool fromwire_commitment_signed(const tal_t *ctx, const void *p, struct channel_id *channel_id, secp256k1_ecdsa_signature *signature, secp256k1_ecdsa_signature **htlc_signature);

/* WIRE: REVOKE_AND_ACK */
u8 *towire_revoke_and_ack(const tal_t *ctx, const struct channel_id *channel_id, const struct secret *per_commitment_secret, const struct pubkey *next_per_commitment_point);
bool fromwire_revoke_and_ack(const void *p, struct channel_id *channel_id, struct secret *per_commitment_secret, struct pubkey *next_per_commitment_point);

/* WIRE: UPDATE_FEE */
u8 *towire_update_fee(const tal_t *ctx, const struct channel_id *channel_id, u32 feerate_per_kw);
bool fromwire_update_fee(const void *p, struct channel_id *channel_id, u32 *feerate_per_kw);

/* WIRE: CHANNEL_REESTABLISH */
u8 *towire_channel_reestablish(const tal_t *ctx, const struct channel_id *channel_id, u64 next_commitment_number, u64 next_revocation_number);
bool fromwire_channel_reestablish(const void *p, struct channel_id *channel_id, u64 *next_commitment_number, u64 *next_revocation_number);

/* WIRE: ANNOUNCEMENT_SIGNATURES */
u8 *towire_announcement_signatures(const tal_t *ctx, const struct channel_id *channel_id, const struct short_channel_id *short_channel_id, const secp256k1_ecdsa_signature *node_signature, const secp256k1_ecdsa_signature *bitcoin_signature);
bool fromwire_announcement_signatures(const void *p, struct channel_id *channel_id, struct short_channel_id *short_channel_id, secp256k1_ecdsa_signature *node_signature, secp256k1_ecdsa_signature *bitcoin_signature);

/* WIRE: CHANNEL_ANNOUNCEMENT */
u8 *towire_channel_announcement(const tal_t *ctx, const secp256k1_ecdsa_signature *node_signature_1, const secp256k1_ecdsa_signature *node_signature_2, const secp256k1_ecdsa_signature *bitcoin_signature_1, const secp256k1_ecdsa_signature *bitcoin_signature_2, const u8 *features, const struct bitcoin_blkid *chain_hash, const struct short_channel_id *short_channel_id, const struct node_id *node_id_1, const struct node_id *node_id_2, const struct pubkey *bitcoin_key_1, const struct pubkey *bitcoin_key_2);
bool fromwire_channel_announcement(const tal_t *ctx, const void *p, secp256k1_ecdsa_signature *node_signature_1, secp256k1_ecdsa_signature *node_signature_2, secp256k1_ecdsa_signature *bitcoin_signature_1, secp256k1_ecdsa_signature *bitcoin_signature_2, u8 **features, struct bitcoin_blkid *chain_hash, struct short_channel_id *short_channel_id, struct node_id *node_id_1, struct node_id *node_id_2, struct pubkey *bitcoin_key_1, struct pubkey *bitcoin_key_2);

/* WIRE: NODE_ANNOUNCEMENT */
u8 *towire_node_announcement(const tal_t *ctx, const secp256k1_ecdsa_signature *signature, const u8 *features, u32 timestamp, const struct node_id *node_id, const u8 rgb_color[3], const u8 alias[32], const u8 *addresses);
bool fromwire_node_announcement(const tal_t *ctx, const void *p, secp256k1_ecdsa_signature *signature, u8 **features, u32 *timestamp, struct node_id *node_id, u8 rgb_color[3], u8 alias[32], u8 **addresses);

/* WIRE: CHANNEL_UPDATE */
u8 *towire_channel_update(const tal_t *ctx, const secp256k1_ecdsa_signature *signature, const struct bitcoin_blkid *chain_hash, const struct short_channel_id *short_channel_id, u32 timestamp, u8 message_flags, u8 channel_flags, u16 cltv_expiry_delta, struct amount_msat htlc_minimum_msat, u32 fee_base_msat, u32 fee_proportional_millionths);
bool fromwire_channel_update(const void *p, secp256k1_ecdsa_signature *signature, struct bitcoin_blkid *chain_hash, struct short_channel_id *short_channel_id, u32 *timestamp, u8 *message_flags, u8 *channel_flags, u16 *cltv_expiry_delta, struct amount_msat *htlc_minimum_msat, u32 *fee_base_msat, u32 *fee_proportional_millionths);

/* WIRE: QUERY_SHORT_CHANNEL_IDS */
u8 *towire_query_short_channel_ids(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, const u8 *encoded_short_ids, const struct tlv_query_short_channel_ids_tlvs *tlvs);
bool fromwire_query_short_channel_ids(const tal_t *ctx, const void *p, struct bitcoin_blkid *chain_hash, u8 **encoded_short_ids, struct tlv_query_short_channel_ids_tlvs *tlvs);

/* WIRE: REPLY_SHORT_CHANNEL_IDS_END */
u8 *towire_reply_short_channel_ids_end(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, u8 complete);
bool fromwire_reply_short_channel_ids_end(const void *p, struct bitcoin_blkid *chain_hash, u8 *complete);

/* WIRE: QUERY_CHANNEL_RANGE */
u8 *towire_query_channel_range(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, u32 first_blocknum, u32 number_of_blocks, const struct tlv_query_channel_range_tlvs *tlvs);
bool fromwire_query_channel_range(const void *p, struct bitcoin_blkid *chain_hash, u32 *first_blocknum, u32 *number_of_blocks, struct tlv_query_channel_range_tlvs *tlvs);

/* WIRE: REPLY_CHANNEL_RANGE */
u8 *towire_reply_channel_range(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, u32 first_blocknum, u32 number_of_blocks, u8 complete, const u8 *encoded_short_ids, const struct tlv_reply_channel_range_tlvs *tlvs);
bool fromwire_reply_channel_range(const tal_t *ctx, const void *p, struct bitcoin_blkid *chain_hash, u32 *first_blocknum, u32 *number_of_blocks, u8 *complete, u8 **encoded_short_ids, struct tlv_reply_channel_range_tlvs *tlvs);

/* WIRE: GOSSIP_TIMESTAMP_FILTER */
u8 *towire_gossip_timestamp_filter(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, u32 first_timestamp, u32 timestamp_range);
bool fromwire_gossip_timestamp_filter(const void *p, struct bitcoin_blkid *chain_hash, u32 *first_timestamp, u32 *timestamp_range);

/* WIRE: OPEN_CHANNEL_OPTION_UPFRONT_SHUTDOWN_SCRIPT */
u8 *towire_open_channel_option_upfront_shutdown_script(const tal_t *ctx, const struct bitcoin_blkid *chain_hash, const struct channel_id *temporary_channel_id, struct amount_sat funding_satoshis, struct amount_msat push_msat, struct amount_sat dust_limit_satoshis, struct amount_msat max_htlc_value_in_flight_msat, struct amount_sat channel_reserve_satoshis, struct amount_msat htlc_minimum_msat, u32 feerate_per_kw, u16 to_self_delay, u16 max_accepted_htlcs, const struct pubkey *funding_pubkey, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *first_per_commitment_point, u8 channel_flags, const u8 *shutdown_scriptpubkey);
bool fromwire_open_channel_option_upfront_shutdown_script(const tal_t *ctx, const void *p, struct bitcoin_blkid *chain_hash, struct channel_id *temporary_channel_id, struct amount_sat *funding_satoshis, struct amount_msat *push_msat, struct amount_sat *dust_limit_satoshis, struct amount_msat *max_htlc_value_in_flight_msat, struct amount_sat *channel_reserve_satoshis, struct amount_msat *htlc_minimum_msat, u32 *feerate_per_kw, u16 *to_self_delay, u16 *max_accepted_htlcs, struct pubkey *funding_pubkey, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *first_per_commitment_point, u8 *channel_flags, u8 **shutdown_scriptpubkey);

/* WIRE: ACCEPT_CHANNEL_OPTION_UPFRONT_SHUTDOWN_SCRIPT */
u8 *towire_accept_channel_option_upfront_shutdown_script(const tal_t *ctx, const struct channel_id *temporary_channel_id, struct amount_sat dust_limit_satoshis, struct amount_msat max_htlc_value_in_flight_msat, struct amount_sat channel_reserve_satoshis, struct amount_msat htlc_minimum_msat, u32 minimum_depth, u16 to_self_delay, u16 max_accepted_htlcs, const struct pubkey *funding_pubkey, const struct pubkey *revocation_basepoint, const struct pubkey *payment_basepoint, const struct pubkey *delayed_payment_basepoint, const struct pubkey *htlc_basepoint, const struct pubkey *first_per_commitment_point, const u8 *shutdown_scriptpubkey);
bool fromwire_accept_channel_option_upfront_shutdown_script(const tal_t *ctx, const void *p, struct channel_id *temporary_channel_id, struct amount_sat *dust_limit_satoshis, struct amount_msat *max_htlc_value_in_flight_msat, struct amount_sat *channel_reserve_satoshis, struct amount_msat *htlc_minimum_msat, u32 *minimum_depth, u16 *to_self_delay, u16 *max_accepted_htlcs, struct pubkey *funding_pubkey, struct pubkey *revocation_basepoint, struct pubkey *payment_basepoint, struct pubkey *delayed_payment_basepoint, struct pubkey *htlc_basepoint, struct pubkey *first_per_commitment_point, u8 **shutdown_scriptpubkey);

/* WIRE: CHANNEL_REESTABLISH_OPTION_DATA_LOSS_PROTECT */
u8 *towire_channel_reestablish_option_data_loss_protect(const tal_t *ctx, const struct channel_id *channel_id, u64 next_commitment_number, u64 next_revocation_number, const struct secret *your_last_per_commitment_secret, const struct pubkey *my_current_per_commitment_point);
bool fromwire_channel_reestablish_option_data_loss_protect(const void *p, struct channel_id *channel_id, u64 *next_commitment_number, u64 *next_revocation_number, struct secret *your_last_per_commitment_secret, struct pubkey *my_current_per_commitment_point);

/* WIRE: CHANNEL_REESTABLISH_OPTION_STATIC_REMOTEKEY */
u8 *towire_channel_reestablish_option_static_remotekey(const tal_t *ctx, const struct channel_id *channel_id, u64 next_commitment_number, u64 next_revocation_number, const struct secret *your_last_per_commitment_secret, const struct pubkey *my_current_per_commitment_point);
bool fromwire_channel_reestablish_option_static_remotekey(const void *p, struct channel_id *channel_id, u64 *next_commitment_number, u64 *next_revocation_number, struct secret *your_last_per_commitment_secret, struct pubkey *my_current_per_commitment_point);

/* WIRE: CHANNEL_UPDATE_OPTION_CHANNEL_HTLC_MAX */
u8 *towire_channel_update_option_channel_htlc_max(const tal_t *ctx, const secp256k1_ecdsa_signature *signature, const struct bitcoin_blkid *chain_hash, const struct short_channel_id *short_channel_id, u32 timestamp, u8 message_flags, u8 channel_flags, u16 cltv_expiry_delta, struct amount_msat htlc_minimum_msat, u32 fee_base_msat, u32 fee_proportional_millionths, struct amount_msat htlc_maximum_msat);
bool fromwire_channel_update_option_channel_htlc_max(const void *p, secp256k1_ecdsa_signature *signature, struct bitcoin_blkid *chain_hash, struct short_channel_id *short_channel_id, u32 *timestamp, u8 *message_flags, u8 *channel_flags, u16 *cltv_expiry_delta, struct amount_msat *htlc_minimum_msat, u32 *fee_base_msat, u32 *fee_proportional_millionths, struct amount_msat *htlc_maximum_msat);


#endif /* LIGHTNING_WIRE_GEN_PEER_WIRE_H */

