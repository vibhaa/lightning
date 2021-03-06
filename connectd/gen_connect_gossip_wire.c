/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/impl_template */

#include <connectd/gen_connect_gossip_wire.h>
#include <assert.h>
#include <ccan/array_size/array_size.h>
#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <stdio.h>

#ifndef SUPERVERBOSE
#define SUPERVERBOSE(...)
#endif


const char *connect_gossip_wire_type_name(int e)
{
	static char invalidbuf[sizeof("INVALID ") + STR_MAX_CHARS(e)];

	switch ((enum connect_gossip_wire_type)e) {
	case WIRE_GOSSIP_NEW_PEER_REPLY: return "WIRE_GOSSIP_NEW_PEER_REPLY";
	case WIRE_GOSSIP_GET_ADDRS: return "WIRE_GOSSIP_GET_ADDRS";
	case WIRE_GOSSIP_NEW_PEER: return "WIRE_GOSSIP_NEW_PEER";
	case WIRE_GOSSIP_GET_ADDRS_REPLY: return "WIRE_GOSSIP_GET_ADDRS_REPLY";
	}

	snprintf(invalidbuf, sizeof(invalidbuf), "INVALID %i", e);
	return invalidbuf;
}




/* WIRE: GOSSIP_NEW_PEER_REPLY */
/* if success: + gossip fd and gossip_store fd */
u8 *towire_gossip_new_peer_reply(const tal_t *ctx, bool success, const struct gossip_state *gs)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIP_NEW_PEER_REPLY);
	towire_bool(&p, success);
	if (!gs)
		towire_bool(&p, false);
	else {
		towire_bool(&p, true);
		towire_gossip_state(&p, gs);
	}

	return memcheck(p, tal_count(p));
}
bool fromwire_gossip_new_peer_reply(const tal_t *ctx, const void *p, bool *success, struct gossip_state **gs)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIP_NEW_PEER_REPLY)
		return false;
 	*success = fromwire_bool(&cursor, &plen);
 	if (!fromwire_bool(&cursor, &plen))
		*gs = NULL;
	else {
		*gs = tal(ctx, struct gossip_state);
		fromwire_gossip_state(&cursor, &plen, *gs);
	}
	return cursor != NULL;
}

/* WIRE: GOSSIP_GET_ADDRS */
/* Connectd asks gossipd for any known addresses for that node. */
u8 *towire_gossip_get_addrs(const tal_t *ctx, const struct node_id *id)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIP_GET_ADDRS);
	towire_node_id(&p, id);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossip_get_addrs(const void *p, struct node_id *id)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIP_GET_ADDRS)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
	return cursor != NULL;
}

/* WIRE: GOSSIP_NEW_PEER */
/* Communication between gossipd and connectd. */
u8 *towire_gossip_new_peer(const tal_t *ctx, const struct node_id *id, bool gossip_queries_feature, bool initial_routing_sync)
{
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIP_NEW_PEER);
	towire_node_id(&p, id);
	/* Did we negotiate LOCAL_GOSSIP_QUERIES? */
	towire_bool(&p, gossip_queries_feature);
	/* Did they offer LOCAL_INITIAL_ROUTING_SYNC? */
	towire_bool(&p, initial_routing_sync);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossip_new_peer(const void *p, struct node_id *id, bool *gossip_queries_feature, bool *initial_routing_sync)
{
	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIP_NEW_PEER)
		return false;
 	fromwire_node_id(&cursor, &plen, id);
 	/* Did we negotiate LOCAL_GOSSIP_QUERIES? */
	*gossip_queries_feature = fromwire_bool(&cursor, &plen);
 	/* Did they offer LOCAL_INITIAL_ROUTING_SYNC? */
	*initial_routing_sync = fromwire_bool(&cursor, &plen);
	return cursor != NULL;
}

/* WIRE: GOSSIP_GET_ADDRS_REPLY */
u8 *towire_gossip_get_addrs_reply(const tal_t *ctx, const struct wireaddr *addrs)
{
	u16 num = tal_count(addrs);
	u8 *p = tal_arr(ctx, u8, 0);

	towire_u16(&p, WIRE_GOSSIP_GET_ADDRS_REPLY);
	towire_u16(&p, num);
	for (size_t i = 0; i < num; i++)
		towire_wireaddr(&p, addrs + i);

	return memcheck(p, tal_count(p));
}
bool fromwire_gossip_get_addrs_reply(const tal_t *ctx, const void *p, struct wireaddr **addrs)
{
	u16 num;

	const u8 *cursor = p;
	size_t plen = tal_count(p);

	if (fromwire_u16(&cursor, &plen) != WIRE_GOSSIP_GET_ADDRS_REPLY)
		return false;
 	num = fromwire_u16(&cursor, &plen);
 	// 2nd case addrs
	*addrs = num ? tal_arr(ctx, struct wireaddr, num) : NULL;
	for (size_t i = 0; i < num; i++)
		fromwire_wireaddr(&cursor, &plen, *addrs + i);
	return cursor != NULL;
}

