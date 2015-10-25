/*
 * Client.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: jeffery
 */

#include "h/Client.h"
#include "h/MesseageMaker.h"
#include "h/FileWriter.h"
#include "h/NetTimer.h"

static void writeScreenMessage(int msg_type,int cur_seq, int max_seq, int paylod_len);

//Constructor when created will create the socket need for data transfer
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

//Method is used to establish connection with the server program
void Client::connectToSever(string ipAddress,int portNumber){
	serv_addr.sin_addr.s_addr = inet_addr(ipAddress.c_str());
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons( portNumber );

	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
		perror("ERROR: failed to connect to server address");
		exit(1);
	}

	//TestCode
	cout << "Successfully connected\n";

    return;
}

//Method runs the client request to the server should be ran after the connection has been established
void Client::requestFile(string* filename){
	//TimeRequest
	NetTimer* nTimer = new NetTimer();
	//Build the file request message to be sent to the server
	MesseageMaker* maker = new MesseageMaker();
	int sendSize = sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int) + sizeof(char)*BUF_SZ;
	void* message = maker->sendGetRequest(filename);
    if( send(sockfd ,(char*) message , sendSize , 0) < 0){
    	cout << "ERROR: failed to send message\n";
    	exit(1);
    }

    //Receive the response from the server
    struct msg_t* responseMessage = new struct msg_t();
    nTimer->startTimer();
    if( recv(sockfd,(char*)responseMessage,sendSize , 0) < 0){
    	cout << "ERROR: failed to receive message\n";
    }
    nTimer->endTimer();

    //Debug
    /*
    //Debug contents
    cout << "Debug Message type " << responseMessage->msg_type << endl;
    cout << "Debug Current Seq " << responseMessage->cur_seq << endl;
    cout << "Debug Max Seq " << responseMessage->max_seq << endl;
    cout << "Debug length " << responseMessage->payload_len << endl;
    cout << "Debug sendSize " << sendSize << endl;
    cout << "Debug Payload " << responseMessage->payload << endl;
    cout << "Debug actual Payload Size " << sizeof(responseMessage->payload) << endl;
    */
    //Debug end

    //Write Screen Message
    writeScreenMessage(responseMessage->msg_type,responseMessage->cur_seq,responseMessage->max_seq,responseMessage->payload_len);

    //Check to see if first response message is of type response
    if(responseMessage->msg_type != MSG_TYPE_GET_RESP){
    	cout << "ERROR: failed to receive a response message from server" << endl;
    	close(sockfd);
    	exit(1);
    }

    //A response from the server means that the file exists. Therefore a file in the data directory needs to be
    //created to store the packets that are received from the server.
    FileWriter* fwriter = new FileWriter(filename);
    string appendData;

    while(responseMessage->msg_type == MSG_TYPE_GET_RESP || responseMessage->msg_type == MSG_TYPE_FINISH){
    	if(responseMessage->msg_type == MSG_TYPE_FINISH){
    		cout << "data transfered successfully\n";
    		break;
    	}

        //Append the to the open file
    	appendData = (char*) responseMessage->payload;
    	fwriter->append(appendData,responseMessage->payload_len);

    	//Send server back an ask message
    	message = maker->sendAckMessage(responseMessage->cur_seq,responseMessage->max_seq);
        if( send(sockfd ,(char*) message , sendSize , 0) < 0){
        	perror("ERROR: failed to send message");
        	exit(1);
        }

        //Wait for next response
        nTimer->startTimer();
        if( recv(sockfd,(char*)responseMessage,sendSize, 0) <= 0){
          	cout << "ERROR: failed to receive a receive message\n";
          	break;
         }
        nTimer->endTimer();

        //Write Screen Message
        writeScreenMessage(responseMessage->msg_type,responseMessage->cur_seq,responseMessage->max_seq,responseMessage->payload_len);
    }

    nTimer->printTotalTime();
    close(sockfd);
}

//Used for printing Screen Message for each received message
static void writeScreenMessage(int msg_type,int cur_seq, int max_seq, int paylod_len){
	if(msg_type < 0 || msg_type > MSG_TYPE_MAX){
		msg_type = MSG_TYPE_INVALID;
	}
    cout << "client: RX ";
    cout << "<" << str_map[msg_type] << "> ";
    cout << "<" << cur_seq << "> ";
    cout << "<" << max_seq << "> ";
    cout << "<" << paylod_len << "> ";
    cout << endl;
}

