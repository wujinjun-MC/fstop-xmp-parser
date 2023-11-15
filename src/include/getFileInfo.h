#ifndef GETFILEINFO_H_
#define GETFILEINFO_H_

#include <regex>
#include <string>

//#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

void storeFileInfo(std::string fname,int section,std::string content);

extern int METHOD;

//extern nlohmann::json j;

#endif
