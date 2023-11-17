#include "include/runThread.h"

using namespace std;
using json = nlohmann::json;

mutex mut;

void runThread(char **argv,int th,int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		runTask(argv[i],th,j);
	}
	mergeJson(j);
	return;
}
