#include "include/runThread2.h"

using namespace std;
using json = nlohmann::json;

//mutex mut2;

void runThread2(char (*fnamelist)[257],int th,int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		runTask(fnames[i],th,j);
	}
	mergeJson(j);
	return;
}
