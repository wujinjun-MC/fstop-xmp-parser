#include "include/getFileInfo.h"

using namespace std;

regex
	re1(".*?rdf:li>(.*?)</.*?")
/*	,re2(".*?xmp(.*?)Rating/.*?")
	,re3(".*?fstop:favorite=\\\"(.*?)\\\"/.*?")
*/
;

void getFileInfo(string fname,string fcontent)
{
	if ( TAGS )
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
				storeFileInfo(fname,0,fcontent.substr(l+8,r-l-8));
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
				storeFileInfo(fname,0,(string)(*iter)[1]);
				++iter;
			}
		}
	}
	if ( RATING || FAVOR )
	{
/*
		if ( METHOD == 1 )
		{
			if ( RATING )
			{
				smatch match;
				if ( regex_match ( fcontent,match,re2 ) )
				{
					printf ("RATING");
					const ssub_match match_1 = match[1];
					storeFileInfo(fname,1,match_1.str());
				}
			}
			if ( FAVOR )
			{
				smatch match;
				if ( regex_match ( fcontent,match,re3 ) )
				{
					printf ("FAVOR");
					const ssub_match match_1 = match[1];
					storeFileInfo(fname,2,match_1.str());
				}
			}
		}
*/
		if ( METHOD == 3 )
		{
			if ( fcontent[320] == 115 )
			{
				if ( FAVOR )
				{
					storeFileInfo(fname,2,fcontent.substr(335,1));
				}
			}
			else if ( fcontent[320] == 109 )
			{
				if ( RATING )
				{
					storeFileInfo(fname,1,fcontent.substr(376,1));
				}
				if ( FAVOR )
				{
					storeFileInfo(fname,2,fcontent.substr(398,1));
				}
			}
			else if ( fcontent[320] == 82 )
			{
				if ( RATING )
				{
					storeFileInfo(fname,1,fcontent.substr(328,1));
				}
				if ( FAVOR )
				{
					storeFileInfo(fname,2,fcontent.substr(350,1));
				}
			}
			else
			{
				if ( FAVOR )
				{
					storeFileInfo(fname,2,fcontent.substr(287,1));
				}
			}
		}
		else
		{
			int l=fcontent.find("fstop:favorite=\""),len=fcontent.size();
			if ( l < len && l != string::npos )
			{
				storeFileInfo(fname,2,fcontent.substr(l+16,1));
			}
			l=fcontent.find("xmp:Rating=\"");
			if ( l < len && l != string::npos )
			{
				storeFileInfo(fname,1,fcontent.substr(l+12,1));
			}
		}
	}
	return;
}

