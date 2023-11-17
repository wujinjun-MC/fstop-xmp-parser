#include "include/runTask.h"

using namespace std;
using json = nlohmann::json;

void runTask(string fname,int& th,json& j)
{
	string filenow=processFileName(fname);
	string nowcont=readFile(filenow);
	if  (nowcont != "")
	{
		//printf("\n");
		getFileInfo(fname,nowcont,th,j);
	}
	return;
}
