#include "include/mergeJson.h"

using namespace std;
using json = nlohmann::json;

mutex mut;

void mergeJson(int& th,json& j)
{
	if (j.empty())
	{
		return;
	}
/*
	cout << "json from thread " << th << ":" << endl;
	cout << j.dump(1) << endl;
*/
	//lock_guard<mutex> lk(mut);
	mut.lock();
	j_final.merge_patch(j);
	mut.unlock();
	return;
}
