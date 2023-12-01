#include "include/getFileInfo.h"

using namespace std;
using json = nlohmann::json;

regex
	re1(".*?rdf:li>(.*?)</.*?")
/*	,re2(".*?xmp(.*?)Rating/.*?")
	,re3(".*?fstop:favorite=\\\"(.*?)\\\"/.*?")
*/
;

void getFileInfo(string& fname,string& fcontent,json& j)
{
	if ( TAGS || REVERSE_TAGS )
	{
		if ( METHOD == 3 || METHOD == 2 )
		{
			int l=fcontent.find(R"(<rdf:li>)"),r,len=fcontent.size();
			while ( l < len )
			{
				r = fcontent.find(R"(</rdf:li)",l);

				if ( r == string::npos )
				{
					break;
				}
				storeFileInfo(j,fname,0,fcontent.substr(l+8,r-l-8));
				if ( METHOD == 3 )
				{
					l = r+15;
				}
				else
				{
					l=fcontent.find(R"(<rdf:li>)",r+5);
				}
			}
		}
		else
		{
			sregex_iterator iter(fcontent.begin(), fcontent.end(), re1);
			sregex_iterator end;
			while(iter != end)
			{
				storeFileInfo(j,fname,0,(string)(*iter)[1]);
				++iter;
			}
		}
	}
	if ( RATING || FAVOR || REVERSE_FAVOR || REVERSE_RATING )
	{
		if ( METHOD == 3 )
		{
			if ( fcontent[320] == 115 )
			{
				if ( FAVOR || REVERSE_FAVOR )
				{
					storeFileInfo(j,fname,2,fcontent.substr(335,1));
				}
			}
			else if ( fcontent[320] == 109 )
			{
				if ( RATING || REVERSE_RATING )
				{
					storeFileInfo(j,fname,1,fcontent.substr(376,1));
				}
				if ( FAVOR || REVERSE_FAVOR )
				{
					storeFileInfo(j,fname,2,fcontent.substr(398,1));
				}
			}
			else if ( fcontent[320] == 82 )
			{
				if ( RATING || REVERSE_RATING )
				{
					storeFileInfo(j,fname,1,fcontent.substr(328,1));
				}
				if ( FAVOR || REVERSE_FAVOR )
				{
					storeFileInfo(j,fname,2,fcontent.substr(350,1));
				}
			}
			else
			{
				if ( FAVOR || REVERSE_FAVOR )
				{
					storeFileInfo(j,fname,2,fcontent.substr(287,1));
				}
			}
		}
		else
		{
			int len=fcontent.size();
			int l;
			if ( FAVOR || REVERSE_FAVOR )
			{
				l=fcontent.find("fstop:favorite=\"");
				if ( l < len && l != string::npos )
				{
					storeFileInfo(j,fname,2,fcontent.substr(l+16,1));
				}
			}
			if ( RATING || REVERSE_RATING )
			{
				l=fcontent.find("xmp:Rating=\"");
				if ( l < len && l != string::npos )
				{
					storeFileInfo(j,fname,1,fcontent.substr(l+12,1));
				}
			}
		}
	}
	//storeFileInfo(j,fname,3,"");
	return;
}

