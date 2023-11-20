#include "include/outputJson.h"

using namespace std;
using json = nlohmann::json;

void outputJson(int& tabs)
{
/*
	for (int i=0;i<threads_num;++i)
	{
		cout << "j[" << i << "]" << endl << j[i] << endl;
		
	}
*/
	//cout << j[0] << endl;
	if (tabs)
	{
		cout << j_final.dump(tabs) << endl;
	}
	else
	{
		cout << j_final.dump() << endl;
	}
	return;
}
