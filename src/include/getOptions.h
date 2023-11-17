#ifndef GETOPTIONS_H_
#define GETOPTIONS_H_

#include <iostream>
#include <unistd.h>
#include <thread>
//#include <string>

#include "global_variables.h"

void printHelp();
std::string processFileName(std::string fname);
std::string readFile(std::string fname);
std::string getFileInfo(std::string fname,std::string fcontent);
void storeInfo(int section,int data_int,long data_long,std::string data_string);
void runThread(char **argv,int th,int start,int end);
void outputJson();

extern std::thread threads[129];
extern int threads_num;

#endif
