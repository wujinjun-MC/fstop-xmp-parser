#ifndef GETFILEINFO_H_
#define GETFILEINFO_H_

#include <regex>
#include <string>

//#include "single_include/nlohmann/json.hpp"
#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

void storeFileInfo(json& j,string& fname,int section,string content);

extern int METHOD;

//extern nlohmann::json j;

#endif
