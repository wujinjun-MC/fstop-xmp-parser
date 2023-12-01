#ifndef RUNTASK_H_
#define RUNTASK_H_

#include <iostream>
#include <mutex>
//#include <atomic>

//#include "single_include/nlohmann/json.hpp"
#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

std::string processFileName(std::string fname);
std::string readFile(std::string fname);
void getFileInfo(string& fname,string& fcontent,json& j);

//extern atomic<nlohmann::json> j;
extern mutex mut;

#endif
