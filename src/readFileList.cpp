#include "include/readFileList.h"

using namespace std;

void readFileList(char fname[257])
{
	if (fname[0] == '-' && fname[1] == 0)
	{
		for(int i=0;i<257;++i)
			//printf("fname[%d]=%d\n",i,fname[i]);
		while (cin.getline(fnamesp[++FILE_COUNT],257))
		{
			//printf("FCNT=%d\n",FILE_COUNT);
			if ( MAX_FILE_COUNT > 0 && MAX_FILE_COUNT < FILE_COUNT+1 )
			{
				return;
			}
		}
		--FILE_COUNT;
	}
	else
	{
		ifstream in(fname);
		if (!in)
		{
			fprintf(stderr,"Can't Open File \"%s\"\n",fname);
			//++open_failed_count;
			return;
		}
		while (in.getline(fnamesp[++FILE_COUNT],257))
		{
			if ( MAX_FILE_COUNT > 0 && MAX_FILE_COUNT < FILE_COUNT+1 )
			{
				return;
			}
		}
		--FILE_COUNT;
		in.close();
	}
	return;
}
