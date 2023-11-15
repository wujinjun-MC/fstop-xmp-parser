#include "include/outputJson.h"

using namespace std;
using json = nlohmann::json;

void outputJson()
{
	cout << j << endl;
	j["Info"]["Avaliable"]=j["Files"].size();
	return;
}
