/*
 * TcpServer.h
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

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

class TcpServer {
private:
	int sockfd, portnumber;
	struct sockaddr_in serv_addr ;
	pthread_t threads[NUMBER_OF_THREADS];


public:
	TcpServer();
	virtual ~TcpServer();
	void bindAndListen(int portNumber, int backlog);
	void acceptRequests();
};

#endif /* TCPSERVER_H_ */
