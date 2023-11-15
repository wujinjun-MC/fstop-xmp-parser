#ifndef GETOPTIONS_H_
#define GETOPTIONS_H_

#include <iostream>
#include <unistd.h>
//#include <string>

#include "global_variables.h"

std::string processFileName(std::string fname);
std::string readFile(std::string fname);
std::string getFileInfo(std::string fname,std::string fcontent);
void outputJson();
void storeInfo(int section,int data_int,long data_long,std::string data_string);
void printHelp();

#endif
