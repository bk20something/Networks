/*
 * ArgHandler.cpp
 *
 *  Created on: Oct 9, 2015
 *      Author: jeffery
 */

#include "ArgHandler.h"

ArgHandler::ArgHandler(int argc, char* argv[]) {
	if(argc == 0){
		cout << "No arguments passed in";
		exit(1);
	}

	programName = argv[0];

	if(argc != 4){
		cout << "Usage: " + programName + " <server-ip> <portNumber> <filename> \n";
		exit(1);
	}
	serverIp = argv[1];
	portNumber = atoi(argv[2]);
	filename = argv[3];
}

ArgHandler::~ArgHandler() {
	// TODO Auto-generated destructor stub
}

int ArgHandler::getPortNumber(){
	return portNumber;
}

string ArgHandler::getProgramName(){
	return programName;
}

string ArgHandler::getIpAddress(){
	return serverIp;
}

string ArgHandler::getFileName(){
	return filename;
}
