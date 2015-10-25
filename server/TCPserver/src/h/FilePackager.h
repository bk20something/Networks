/*
 * FilePackager.h
 *
 *  Created on: Oct 11, 2015
 *      Author: jeffery
 */

#ifndef FILEPACKAGER_H_
#define FILEPACKAGER_H_

#include "message.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class FilePackager {
private:
	vector<struct msg_t*> packages;
	bool fileOpened;
	int maxSequenceValue;
public:
	FilePackager(string filename,int bufferSize);
	virtual ~FilePackager();
	bool fileExists();
	struct msg_t* getMessage(int value);
	int numberOfPackages();
};

#endif /* FILEPACKAGER_H_ */
