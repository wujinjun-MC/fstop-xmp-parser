#include "include/storeFileInfo.h"

using namespace std;
using json = nlohmann::json;

json j_final;

void storeFileInfo(json& j,int& th,string& fname,int section,string content)
{
//	fprintf(stderr,"%d %c\n",section,content[0]);
	if ( JSON_OUTPUT )
	{
		if (!section)
		{
			j["files"][fname]["tags"].push_back(content);
		}
		else if ( section == 2 )
		{
			if ( content[0] == '1' )
			{
				j["files"][fname]["favorite"]=true;
			}
/*
			else
			{
				j[fname]["favorite"]=false;
			}
*/
		}
		else if ( section == 1 )
		{
			j["files"][fname]["rating"]=content[0]-48;
		}
		else if ( section == 3 )
		{
			j["files"][fname]["last_update"]=time(0);
		}
	}
    return;
}
