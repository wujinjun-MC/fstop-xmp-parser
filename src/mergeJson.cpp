#include "include/mergeJson.h"

using namespace std;
using json = nlohmann::json;

void mergeJson(int& th,json& j)
{
	lock_guard<mutex> lk(mut);
	if (j.empty())
	{
		return;
	}
/*
	cout << "json from thread " << th << ":" << endl;
	cout << j.dump(1) << endl;
*/
	j_final.merge_patch(j);
	return;
}
