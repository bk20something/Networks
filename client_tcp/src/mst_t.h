/*
 * mst_t.h
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#ifndef MST_T_H_
#define MST_T_H_

#define BUF_SZ 1000

enum msg_type_t{
	MSG_TYPE_INVALID,
	MSG_TYPE_GET,
	MSG_TYPE_GET_ERR,
	MSG_TYPE_GET_RESP,
	MSG_TYPE_GET_ACK,
	MSG_TYPE_FINISH,
	MSG_TYPE_MAX
};

struct msg_t{
	enum msg_type_t msg_type;
	int cur_seq;
	int max_seq;
	int payload_len;
	unsigned char payload[BUF_SZ];
};


#endif /* MST_T_H_ */
