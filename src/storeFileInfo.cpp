#include "include/storeFileInfo.h"

using namespace std;
using json = nlohmann::json;

json j_final;

void storeFileInfo(json& j,string& fname,int section,string content)
{
//	fprintf(stderr,"%d %c\n",section,content[0]);
	if ( JSON_OUTPUT )
	{
		switch (section)
		{
			case 0:
				if ( TAGS )
				{
					j["files"][fname]["tags"].push_back(content);
				}
				if ( REVERSE_TAGS )
				{
					j["items"]["tags"][content].push_back(fname);
				}
				break;
			case 1:
				if ( RATING )
				{
					j["files"][fname]["rating"]=content[0]-48;
				}
				if ( REVERSE_RATING )
				{
					j["items"]["ratings"][content[0]-48].push_back(fname);
				}
				break;
			case 2:
				if ( FAVOR )
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
				if ( REVERSE_FAVOR )
				{
					if(content[0] == '1')
					{
					j["items"]["favorite"].push_back(fname);
					}
				}
				break;
			case 3:
				j["files"][fname]["last_update"]=time(0);
				break;
/*
			case 4:
				j["items"]["tags"][content].push_back(fname);
				break;
			case 5:
				j["items"]["ratings"][content].push_back(fname);
				break;
			case 6:
				if(content[0] == '1')
				{
				j["items"]["favorite"][true].push_back(fname);
				}
				else
				{
					j["items"]["favorite"][false].push_back(fname);
				}
*/
		}
	}
    return;
}
