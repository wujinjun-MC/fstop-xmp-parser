#ifndef GETFILEINFO_H_
#define GETFILEINFO_H_

#include <regex>
#include <string>
#include <streambuf>
#include <fstream>

//#include "single_include/nlohmann/json.hpp"
#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

extern int METHOD;

void storeFileInfo(json& j,string& fname,int section,string content);

//extern nlohmann::json j;

#endif
