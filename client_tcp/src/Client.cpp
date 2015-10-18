/*
 * Client.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: jeffery
 */

#include "Client.h"
#include "MesseageMaker.h"

Client::Client() {
	//open tcp socket connection
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		cout << "ERROR: failed to create client socket\n";
		exit(1);
	}
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::connectToSever(string ipAddress,int portNumber){
	serv_addr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons( portNumber );

	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
		cout << "ERROR: failed to connect to server address\n";
		exit(1);
	}

	//TestCode
	cout << "Successfully connected";

	MesseageMaker* maker = new MesseageMaker();
	void* message = "Fuck you bitch\n";
    if( send(sockfd ,(char*) message.c_str() , strlen(message.c_str()) , 0) < 0){
    	puts("Send failed");
    	exit(1);
    }
    close(sockfd);
    return;
}

