/*
 * FilePackager.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#include "FilePackager.h"

FilePackager::FilePackager(string filename,int bufferSize) {
	ifstream fileReader;
	int size;

	fileOpened = false;
	fileReader.open(filename.c_str(), ios::binary|ios::ate);
	if(fileReader.is_open()){
		fileOpened = true;

		//get the end position
		size = fileReader.tellg();
		cout << size << " bytes"; //Debug

		//go back to front of file
		fileReader.seekg (0, ios::beg);
		int readSize;
		for(int i = 0; i < (size/BUF_SZ)+1 ; i++){
			//set the size you read in from the file
			if(i ==(size/BUF_SZ)){
				readSize = size - (i * BUF_SZ);
			}
			else{
				readSize = BUF_SZ;
			}

			//build message struct
			struct msg_t* message = new msg_t();
			message->cur_seq = i+1;
			message->max_seq = (size/BUF_SZ)+1;
			message->payload_len = readSize;
			fileReader.read ((char*)message->payload, readSize);

			//add struct to vector
			packages.push_back(message);
		}
	}
}

FilePackager::~FilePackager() {
	// TODO Auto-generated destructor stub
}

bool FilePackager::fileExists(){
	return fileOpened;
}

struct msg_t* FilePackager::getMessage(int value){
	return packages.at(value);
}




