#ifndef MERGEJSON_H_
#define MERGEJSON_H_

#include <iostream>
#include <mutex>

#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

using namespace std;
using json = nlohmann::json;

extern nlohmann::json j_final;
extern int threads_num;
extern mutex mut;

#endif
