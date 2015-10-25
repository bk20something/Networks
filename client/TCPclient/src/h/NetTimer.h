/*
 * NetTimer.h
 *
 *  Created on: Oct 24, 2015
 *      Author: jeffery
 */

#ifndef NETTIMER_H_
#define NETTIMER_H_

#include <time.h>
#include <stdint.h> //unit64

#include <iostream>
using namespace std;

#define BILLION 1000000000L

class NetTimer {
private:
	struct timespec start, end;
	uint64_t diff, totalTime;

public:
	NetTimer();
	virtual ~NetTimer();
	void startTimer();
	void endTimer();
	void printTotalTime();
};

#endif /* NETTIMER_H_ */
