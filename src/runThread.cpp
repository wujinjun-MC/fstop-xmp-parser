#include "include/runThread.h"

using namespace std;
using json = nlohmann::json;

void runThread(int th,char *argv[],int start,int end)
{
	json j;
	for (int i=start;i<end;++i)
	{
		getFileInfo(argv[i],j);
	}
	mergeJson(th,j);
	return;
}
