#include "include/main.h"

//global variables start
bool JSON_OUTPUT=false,TAGS=false,FAVOR=false,RATING=false;
int METHOD=3,open_failed_count=0,threads_num=1,MAX_FILE_COUNT=0;
//global variables end

int main(int argc,char *argv[])
{
	return getOptions(argc,argv);
}
