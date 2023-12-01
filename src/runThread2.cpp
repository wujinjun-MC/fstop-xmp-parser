#include "include/runThread2.h"

using namespace std;
using json = nlohmann::json;

//mutex mut2;

void runThread2(int th,int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		runTask(fnames[i],j);
	}
	mergeJson(th,j);
	return;
}
