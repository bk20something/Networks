/*
 * MesseageMaker.h
 *
 *  Created on: Oct 15, 2015
 *      Author: jeffery
 */

#ifndef MESSEAGEMAKER_H_
#define MESSEAGEMAKER_H_

#include "message.h"

#include <climits>
#include <arpa/inet.h>
#include <string.h>

#include <iostream>
using namespace std;

class MesseageMaker {
private:
	struct msg_t* getRequest;
	struct msg_t* ackMessage;
public:
	MesseageMaker();
	virtual ~MesseageMaker();
	struct msg_t* sendGetRequest(string* fileName);
	struct msg_t* sendAckMessage(int cur_seq, int max_seq);
};

#endif /* MESSEAGEMAKER_H_ */
