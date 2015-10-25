/*
 * MesseageMaker.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: jeffery
 */

#include "h/MesseageMaker.h"

MesseageMaker::MesseageMaker() {
	getRequest = new msg_t();
	ackMessage = new msg_t();
	finMessage = new msg_t();
}

MesseageMaker::~MesseageMaker() {
}

//Used to build a get request message
struct msg_t* MesseageMaker::sendGetRequest(string* fileName){
	getRequest->msg_type = MSG_TYPE_GET;
	getRequest->cur_seq = 0;
	getRequest->max_seq = 0;
	memset(getRequest->payload, 0, sizeof(getRequest->payload));
	strcpy( (char*) getRequest->payload, fileName->c_str() );
	getRequest->payload_len = BUF_SZ;

	return getRequest;
}

//Used to build an ack message
struct msg_t* MesseageMaker::sendAckMessage(int cur_seq, int max_seq){
	ackMessage->msg_type = MSG_TYPE_GET_ACK;
	ackMessage->cur_seq = cur_seq;
	ackMessage->max_seq = max_seq;
	memset(ackMessage->payload, 0, sizeof(ackMessage->payload));
	ackMessage->payload_len = BUF_SZ;

	return ackMessage;
}

struct msg_t* MesseageMaker::sendFinMessage(int cur_seq, int max_seq){
	finMessage->msg_type = MSG_TYPE_FINISH;
	finMessage->cur_seq = cur_seq;
	finMessage->max_seq = max_seq;
	memset(finMessage->payload, 0, sizeof(finMessage->payload));
	finMessage->payload_len = BUF_SZ;

	return finMessage;
}

