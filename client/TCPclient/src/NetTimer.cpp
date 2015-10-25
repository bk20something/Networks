/*
 * NetTimer.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: jeffery
 */

#include "h/NetTimer.h"

NetTimer::NetTimer() {
	 diff = 0;
	 totalTime = 0;
}

NetTimer::~NetTimer() {
	// TODO Auto-generated destructor stub
}

void NetTimer::startTimer(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
}

void NetTimer::endTimer(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	totalTime  = totalTime + diff;
}

void NetTimer::printTotalTime(){
	cout << "Total time " << totalTime << " nanoseconds" << endl;
}
