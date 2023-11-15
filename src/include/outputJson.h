#ifndef OUTPUTJSON_H_
#define OUTPUTJSON_H_

#include <iostream>

#include "single_include/nlohmann/json.hpp"

extern nlohmann::json j;
void storeInfo(int section,int data_int,long data_long,std::string data_string);

#endif
