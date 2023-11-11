#ifndef GETOPTIONS_H_
#define GETOPTIONS_H_

#include <iostream>
#include <unistd.h>
#include <string>

#include "global_variables.h"

std::string processFileName(std::string fname);
std::string readFile(std::string fname);
std::string getFileInfoJson(std::string fname,std::string fcontent);
void outputJson();

#endif