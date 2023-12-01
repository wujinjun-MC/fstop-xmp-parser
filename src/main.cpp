#include "include/main.h"

//global variables start
bool JSON_OUTPUT=false,TAGS=false,FAVOR=false,RATING=false,REVERSE_TAGS=false,REVERSE_FAVOR=false,REVERSE_RATING=false,INFO=true,READ_FILE_LIST=false;
int METHOD=2,open_failed_count=0,threads_num=1,MAX_FILE_COUNT=0,FILE_COUNT=0,FILE_LIST_COUNT=0,TABS=0;
//global variables end

int main(int argc,char *argv[])
{
	return getOptions(argc,argv);
}
