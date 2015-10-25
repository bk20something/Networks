/*
 * Client.h
 *
 *  Created on: Oct 14, 2015
 *      Author: jeffery
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <cerrno>
#include <cstdio>
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

class Client {
private:
	int sockfd, portnumber;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr ;

public:
	Client();
	virtual ~Client();
	void connectToSever(string ipAddress,int portNumber);
	void requestFile(string* filename);
};

#endif /* CLIENT_H_ */
