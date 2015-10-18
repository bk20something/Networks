//============================================================================
// Name        : server_tcp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "ArgHandler.h"
#include "mst_t.h"
#include "FilePackager.h"

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
	//Handle and store arguments
	ArgHandler* args = new ArgHandler(argc, argv);
	FilePackager* fpack = new FilePackager("/home/jeffery/Desktop/login",666);
	struct msg_t* message = fpack->getMessage(0);
	cout << message->payload;
}
