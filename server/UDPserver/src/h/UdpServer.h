/*
 * UdpServer.h
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "debugMarcos.h"
#include "message.h"
#include "FilePackager.h"

#include <sys/stat.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
using namespace std;

#define BUFFER_SIZE 256
#define NUMBER_OF_THREADS 12000

class UdpServer {
private:
	int sockfd, portnumber;
	struct sockaddr_in serv_addr, cli_addr ;
	socklen_t cli_addrlen;
	int sendSize;
	//unsigned char buffer[sendSize];

public:
	UdpServer();
	virtual ~UdpServer();
	void bindAndListen(int portNumber, int backlog);
	void acceptRequests();
};

#endif /* UdpServer_H_ */
