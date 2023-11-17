#ifndef OUTPUTJSON_H_
#define OUTPUTJSON_H_

#include <iostream>

#include "single_include/nlohmann/json.hpp"
#include "global_variables.h"

extern nlohmann::json j_final;
extern nlohmann::json j[129];
//void storeInfo(int section,int data_int,long data_long,std::string data_string);

#endif
