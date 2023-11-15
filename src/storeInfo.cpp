#include "include/storeInfo.h"

using namespace std;

void storeInfo(int section,int data_int,long data_long,string data_string)
{
	if ( !section )
	{
		j["info"]["last_update_time_stamp"]=data_long;
	}
	else if ( section == 1 )
	{
		j["info"]["file_count"]=data_int;
	}
	else if ( section == 2 )
	{
		j["info"]["file_error_count"]=data_int;
	}
	return;
}
