#ifndef RUNTHREAD2_H_
#define RUNTHREAD2_H_

#include <iostream>

#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

//void runTask(string fname,json& j);
void getFileInfo(string fname,json& j);
void mergeJson(int& th,json& j);

extern int threads_num;
extern char fnames[500000][257];

#endif
