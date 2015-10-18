//============================================================================
// Name        : client_tcp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ArgHandler.h"
#include "Client.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	ArgHandler* args = new ArgHandler(argc, argv);
	Client* client = new Client();
	client->connectToSever(args->getIpAddress(), args->getPortNumber());
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
