/*
 * FileWriter.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: jeffery
 */

#include "h/FileWriter.h"

//Constructor for the File Writer Object
//This constructor will take in the name of a file and look inside the data directory to see if it exits
//If it does it will truncate the file if it doesn't it will create the file
FileWriter::FileWriter(string* fileName) {
	this->fileName = fileName->c_str();
	this->fileName = "TCPclient/src/data/" + this->fileName;
	ofstream file;
	file.open(this->fileName.c_str(),ofstream::trunc);
	file.close();

}

FileWriter::~FileWriter() {
	// TODO Auto-generated destructor stub
}

//Will append data on an exiting file
void FileWriter::append(string appenedData, int writeSize){
	ofstream file;
	file.open(fileName.c_str(),ofstream::app);
	file.write(appenedData.c_str(),writeSize);
	file.close();
}

