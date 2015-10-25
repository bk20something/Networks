/*
 * FileWriter.h
 *
 *  Created on: Oct 18, 2015
 *      Author: jeffery
 */

#ifndef FILEWRITER_H_
#define FILEWRITER_H_

#include <fstream>

#include <iostream>
using namespace std;

class FileWriter {
private:
	string fileName;
public:
	FileWriter(string* fileName);
	virtual ~FileWriter();
	void append(string appenedData,int writeSize);
};

#endif /* FILEWRITER_H_ */
