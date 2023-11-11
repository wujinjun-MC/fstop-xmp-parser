#include "include/getFileInfoJson.h"

using namespace std;
using json = nlohmann::json;

json j;
int u=0;

//tring strRegexMatch = ".*?rdf:li>(.*?)</.*?";
regex re1(".*?rdf:li>(.*?)</.*?");

void getFileInfoJson(string fname,string fcontent)
{
        if (TAGS)
        {
                sregex_iterator iter(fcontent.begin(), fcontent.end(), re1);
                sregex_iterator end;
                u=0;
                while(iter != end)
                {
                        j[fname]["tags"][u++]=(string)(*iter)[1];
                        ++iter;
                }
        }
        if(RATING || FAVOR)
        {
                if (fcontent[319] == 'f')
                {
                        if (FAVOR)
                        {
                                if (fcontent[335] == '0')
                                {
                                        j[fname]["favorite"]=false;
                                }
                                else
                                {
                                        j[fname]["favorite"]=true;
                                }
                        }
                }
                else
                {
                        if (RATING)
                        {
                                j[fname]["rating"]=fcontent[376]-48;
                        }
                        if (FAVOR)
                        {
                                if (fcontent[398] == '0')
                                {
                                        j[fname]["favorite"]=false;
                                }
                                else
                                {
                                        j[fname]["favorite"]=true;
                                }
                        }
                }
        }
        return;
}

