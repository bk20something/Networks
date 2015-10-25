/*
 * UdpServer.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#include "h/UdpServer.h"

int file_exist (const char *filename);
static void writeScreenMessage(int msg_type,int cur_seq, int max_seq, int paylod_len);



//Used to construct the Tcp server will create the socket when called
UdpServer::UdpServer() {
	sendSize = sizeof(int) + sizeof(int) + sizeof(int) + sizeof(int) + sizeof(char)*BUF_SZ;
	cli_addrlen = sizeof(cli_addr);
	//open tcp socket connection
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0){
		cout << "ERROR: failed to create server socket\n";
		exit(1);
	}
}

UdpServer::~UdpServer() {

}

//Used to bind the socket that was created
void UdpServer::bindAndListen(int portNumber, int backlog){
	//Check and set port number
	if(portNumber < 0){
		cout << "ERROR: Invalid port number\n";
		exit(1);
	}
	this->portnumber = portNumber;

	//Bind socket to port number
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(this->portnumber);
	if( bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) ){
		cout << "ERROR: Failed to bind socket to port\n";
		exit(1);
	}

	//listen on socket
	listen(sockfd, backlog);
	char str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(serv_addr.sin_addr), str, INET_ADDRSTRLEN);
	cout << "listing on port " << ntohs(serv_addr.sin_port) << "\n ip address is " <<  ntohs(serv_addr.sin_addr.s_addr)  << "\n";
}

//Used to mulit thread the server when a new request is accepted it will create a new thread and detach it
//The detach thread runs the code in runnable
void UdpServer::acceptRequests(){
	while(1){
	    //Read client request
		struct msg_t* message = new struct msg_t();
		int recvlen;

		//check for msg of type get
		recvlen = recvfrom(sockfd, message, sendSize, 0, (struct sockaddr *)&cli_addr, &cli_addrlen);

	    //Write out screen message when a request is received
		if(recvlen > 0){
	    	writeScreenMessage(message->msg_type,message->cur_seq,message->max_seq,message->payload_len);
			#if ECHO == 1
	    		cout << "Payload: " << message->payload << endl;
			#endif
	    }
	    else{
	    	perror("problem with server receiving: ");
	    }

	    //check to see if file exits in data folder
	    bool exist = 0;
	    string filename = (char*) message->payload;
	    filename = "UDPserver/src/data/" + filename;
	    exist = file_exist(filename.c_str());
		#if ECHO == 1
			cout << "Searching for : " << filename << endl;
			cout << "File existence is " << exist << endl;
		#endif

		//if the pthread dosen't exist send message of type MSG_TYPE_GET_ERR
		if(!exist){
			struct msg_t* errMessage = new struct msg_t();
			errMessage->msg_type = MSG_TYPE_GET_ERR;
			errMessage->cur_seq = 1;
			errMessage->max_seq = message->max_seq;
			errMessage->payload_len = 0;
			memset(errMessage->payload, 0, sizeof(errMessage->payload));
		    if( sendto(sockfd ,(char*) errMessage , sendSize , 0,(struct sockaddr *)&cli_addr, cli_addrlen) < 0){
		    	cout << "ERROR: failed to send error message\n";
		    }
		    //close socket and exit the tread
		    continue;
		}

		//Send back file packages
		FilePackager* fpack = new FilePackager(filename,BUF_SZ);
		int maxPackageNumber = fpack->numberOfPackages();
		int pakageCount = 0;

	    if( sendto(sockfd ,(char*) fpack->getMessage(pakageCount) , sendSize , 0,(struct sockaddr *)&cli_addr, cli_addrlen) < 0){
	    	cout << "ERROR: failed to send message\n";
	    	exit(1);
	    }


		//Wait for the first client ack
	    recvlen = recvfrom(sockfd, message, sendSize, 0, (struct sockaddr *)&cli_addr, &cli_addrlen);
	    if( recvlen > 0){
	    	writeScreenMessage(message->msg_type,message->cur_seq,message->max_seq,message->payload_len);
			#if ECHO == 1
	    		cout << "Payload: " << message->payload << endl;
			#endif
	    }
	    else{
	    	perror("problem with server receiving: ");
	    	continue;
	    }

	    pakageCount++;

	    //Continue to wait for client ack
	    while(message->msg_type == MSG_TYPE_GET_ACK && pakageCount < maxPackageNumber){
	        if( sendto(sockfd ,(char*) fpack->getMessage(pakageCount) , sendSize , 0,(struct sockaddr *)&cli_addr, cli_addrlen) < 0){
	        	cout << "ERROR: failed to send error message\n";
	        	continue;
	        }
	        pakageCount++;
	        recvlen = recvfrom(sockfd, message, sendSize, 0, (struct sockaddr *)&cli_addr, &cli_addrlen);
	        if( recvlen > 0){
	        	writeScreenMessage(message->msg_type,message->cur_seq,message->max_seq,message->payload_len);
	    		#if ECHO == 1
	        		cout << "Payload: " << message->payload << endl;
	    		#endif
	        }
	    }
	    pakageCount = 0;
	}
}

int file_exist (const char* filename){
	//debug the current working directory
	/*
	char cwd[FILENAME_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
		perror("getcwd() error");
	string testName = "src/data/input_large.txt";
	*/
	struct stat   buffer;
	return (stat (filename, &buffer) == 0);
}

//Used for printing Screen Message for each received message
static void writeScreenMessage(int msg_type,int cur_seq, int max_seq, int paylod_len){
	if(msg_type < 0 || msg_type > MSG_TYPE_MAX){
		msg_type = MSG_TYPE_INVALID;
	}
    cout << "server: RX ";
    cout << "<" << str_map[msg_type] << "> ";
    cout << "<" << cur_seq << "> ";
    cout << "<" << max_seq << "> ";
    cout << "<" << paylod_len << "> ";
    cout << endl;
}



