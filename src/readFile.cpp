#include "include/readFile.h"

using namespace std;

string readFile(string fname)
{
        ifstream in(fname);
        if (!in)
        {
                fprintf(stderr,"Can't Open File \"%s\"\n",fname.c_str());
                return "";
        }
        string cont((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        in.close();
       return cont;
}
