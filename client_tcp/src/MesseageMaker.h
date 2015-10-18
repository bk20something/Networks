/*
 * MesseageMaker.h
 *
 *  Created on: Oct 15, 2015
 *      Author: jeffery
 */

#ifndef MESSEAGEMAKER_H_
#define MESSEAGEMAKER_H_

#include "mst_t.h"

#include <string.h>

#include <iostream>
using namespace std;

class MesseageMaker {
private:
	struct msg_t* getRequest;
public:
	MesseageMaker();
	virtual ~MesseageMaker();
	struct msg_t* sendGetRequest();
};

#endif /* MESSEAGEMAKER_H_ */
