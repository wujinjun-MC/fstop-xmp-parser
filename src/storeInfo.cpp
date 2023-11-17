#include "include/storeInfo.h"

using namespace std;

void storeInfo(int section,int data_int,long data_long,string data_string)
{
	if ( !section )
	{
		j_final["info"]["last_update_time_stamp"]=data_long;
	}
	else if ( section == 1 )
	{
		j_final["info"]["file_count"]=data_int;
	}
/*
	else if ( section == 2 )
	{
		j["info"]["file_error_count"]=data_int;
	}
*/
	else// if ( section == 3 )
	{
		j_final["info"]["threads_num"]=data_int;
	}
	return;
}
