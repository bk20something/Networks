/*
 * MesseageMaker.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: jeffery
 */

#include "MesseageMaker.h"

MesseageMaker::MesseageMaker() {
	getRequest = new msg_t();
}

MesseageMaker::~MesseageMaker() {
}

struct msg_t* MesseageMaker::sendGetRequest(){
	getRequest->msg_type = MSG_TYPE_GET ;
	getRequest->cur_seq = 0;
	getRequest->max_seq = 0;
	getRequest->payload_len = 0;
	memset(getRequest->payload, 0, sizeof(getRequest->payload));

	return getRequest;
}

