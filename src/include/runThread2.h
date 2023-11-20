#ifndef RUNTHREAD2_H_
#define RUNTHREAD2_H_

#include <iostream>
#include <mutex>

#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

void runTask(string fname,int& th,json& j);
void mergeJson(json& j);

extern int threads_num;
extern char fnames[500000][257];

#endif