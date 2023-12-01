#include "include/getFileInfo.h"

using namespace std;
using json = nlohmann::json;
/*
regex
	re1(".*?rdf:li>(.*?)</.*?")
	,re2(".*?xmp(.*?)Rating/.*?")
	,re3(".*?fstop:favorite=\\\"(.*?)\\\"/.*?")
;
*/

inline void readFile(string& cont,string fname)
{
	ifstream in(fname);
	if (!in)
	{
		fprintf(stderr,"Can't Open File \"%s\"\n",fname.c_str());
		//++open_failed_count;
		return;
	}
	cont=string((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	in.close();
	return;
}

void getFileInfo(string fname,json& j)
{
/*
	fname.erase(fname.rfind("."),fname.size());
	fname += ".xmp";
*/
	string fcontent,fxmpname = fname.substr(0,fname.rfind(".")) + ".xmp";
	readFile(fcontent,fxmpname);
	if ( fcontent == "" )
	{
		return;
	}
	if ( TAGS || REVERSE_TAGS )
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
	if ( RATING || FAVOR || REVERSE_FAVOR || REVERSE_RATING )
	{
		if ( METHOD == 2 )
		{
			switch ( fcontent[320] )
			{
				case 115:
					if ( FAVOR || REVERSE_FAVOR )
					{
						storeFileInfo(j,fname,2,fcontent.substr(335,1));
					}
					break;
				case 109:
					if ( RATING || REVERSE_RATING )
					{
						storeFileInfo(j,fname,1,fcontent.substr(376,1));
					}
					if ( FAVOR || REVERSE_FAVOR )
					{
						storeFileInfo(j,fname,2,fcontent.substr(398,1));
					}
					break;
				case 82:
					if ( RATING || REVERSE_RATING )
					{
						storeFileInfo(j,fname,1,fcontent.substr(328,1));
					}
					if ( FAVOR || REVERSE_FAVOR )
					{
						storeFileInfo(j,fname,2,fcontent.substr(350,1));
					}
					break;
				default:
					if ( FAVOR || REVERSE_FAVOR )
					{
						storeFileInfo(j,fname,2,fcontent.substr(287,1));
					}
					break;
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

