//============================================================================
// Name        : server_udp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "h/ArgHandler.h"
#include "h/message.h"
#include "h/FilePackager.h"
#include "h/UdpServer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	ArgHandler* args = new ArgHandler(argc,argv);
	UdpServer* udp = new UdpServer();
	udp->bindAndListen(args->getPortNumber(),10);
	udp->acceptRequests();
	cout << "!!!END OF PROGRAM!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
