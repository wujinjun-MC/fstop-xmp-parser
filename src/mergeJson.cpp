#include "include/mergeJson.h"

using namespace std;
using json = nlohmann::json;

void mergeJson(json j)
{
	lock_guard<mutex> lk(mut);
	j_final.merge_patch(j);
	return;
}
