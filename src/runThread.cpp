#include "include/runThread.h"

using namespace std;
using json = nlohmann::json;

mutex mut;

void runThread(int th,char *argv[],int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		runTask(argv[i],j);
	}
	mergeJson(th,j);
	return;
}
