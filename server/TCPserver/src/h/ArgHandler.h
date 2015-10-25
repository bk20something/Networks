/*
 * ArgHandler.h
 *
 *  Created on: Oct 9, 2015
 *      Author: jeffery
 */

#ifndef ARGHANDLER_H_
#define ARGHANDLER_H_

//Includes
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

//Class declaration
class ArgHandler {
private:
	string programName;
	int portNumber;

public:
	ArgHandler(int argc, char* argv[]);
	virtual ~ArgHandler();
	int getPortNumber();
	string getProgramName();
};

#endif /* ARGHANDLER_H_ */
