/*
 * ArgHandler.cpp
 *
 *  Created on: Oct 9, 2015
 *      Author: jeffery
 */

#include "h/ArgHandler.h"

//Used to handle arguments that passed into the server
ArgHandler::ArgHandler(int argc, char* argv[]) {
	if(argc == 0){
		cout << "No arguments passed in";
		exit(1);
	}

	programName = argv[0];

	if(argc != 2){
		cout << "Usage: " + programName + " <portNumber> \n";
		exit(1);
	}
	portNumber = atoi(argv[1]);
}

ArgHandler::~ArgHandler() {
	// TODO Auto-generated destructor stub
}

//Methods used to acess parameter that are passed into the server
int ArgHandler::getPortNumber(){
	return portNumber;
}

string ArgHandler::getProgramName(){
	return programName;
}
