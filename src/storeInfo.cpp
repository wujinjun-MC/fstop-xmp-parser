#include "include/storeInfo.h"

using namespace std;

void storeInfo(int section,int data_int,long data_long,string data_string)
{
	switch (section)
	{
		case 0:
			j_final["info"]["last_update_time_stamp"]=data_long;
			break;
		case 1:
			j_final["info"]["file_count"]=data_int;
			break;
		case 3:
			j_final["info"]["threads_num"]=data_int;
			break;
		case 4:
			j_final["info"]["JSON_OUTPUT"]=JSON_OUTPUT;
			j_final["info"]["TAGS"]=TAGS;
			j_final["info"]["RATING"]=RATING;
			j_final["info"]["READ_FILE_LIST"]=READ_FILE_LIST;
			j_final["info"]["METHOD"]=METHOD;
			j_final["info"]["FAVORITE"]=FAVOR;
			if (MAX_FILE_COUNT)
			{
				j_final["info"]["MAX_FILE_COUNT"]=MAX_FILE_COUNT;
			}
			if (FILE_LIST_COUNT)
			{
				j_final["info"]["FILE_LIST_COUNT"]=-FILE_LIST_COUNT;
			}
			break;
		default:
			abort();
	}
	
	return;
}
