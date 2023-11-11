#include "include/getFileInfoJson.h"

using namespace std;
using json = nlohmann::json;

json j;
int u=0;

//tring strRegexMatch = ".*?rdf:li>(.*?)</.*?";
regex re1(".*?rdf:li>(.*?)</.*?");

void getFileInfoJson(string fname,string fcontent)
{
        //regex re1(strRegexMatch);
        sregex_iterator iter(fcontent.begin(), fcontent.end(), re1);
        sregex_iterator end;
        u=0;
        while(iter != end)
        {
                j[fname]["tags"][u++]=(string)(*iter)[1];
                ++iter;
        }
        return;
}

