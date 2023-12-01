#include "include/runThread2.h"

using namespace std;
using json = nlohmann::json;

void runThread2(int th,int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		getFileInfo(fnames[i],j);
	}
	mergeJson(th,j);
	return;
}
