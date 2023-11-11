#include "include/processFileName.h"

using namespace std;

string processFileName(string fname)
{
        return fname.substr(0,fname.rfind(".")) + ".xmp";
}
