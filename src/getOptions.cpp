//reference: https://www.codenong.com/18079340/

#include "include/getOptions.h"
using namespace std;

int getOptions (int argc, char **argv)
{
	char *cvalue = NULL;
	int index;
	int op;

	opterr = 0;

	while ((op = getopt (argc, argv,"hjtrfm:")) != -1)
	{
	    //printf("start getopt()\n");
		switch (op)
		{
			case 'h':
				printf(R"(Still in early development
)");
				printHelp();
				return 0;
			case 'j':
				JSON_OUTPUT = true;
				break;
			case 't':
				TAGS = true;
				break;
			case 'r':
				RATING = true;
				break;
			case 'f':
				FAVOR = true;
				break;
			case 'm':
				METHOD = optarg[0]-48;
				//printf ("METHOD%d\n",METHOD);
				break;
			case '?':
				if (optopt == 'm')
				{
					fprintf (stderr,"Option -%c requires an argument.\n", optopt);
				}
				else if (isprint (optopt))
				{
					fprintf (stderr,"Unknown option `-%c'.\n", optopt);
				}
				else
				{
					fprintf (stderr,"Unknown option character `\\\\x%x'.\n",optopt);
				}
				return 2;
			default:
				abort ();
		}
	}
	if (! (RATING || TAGS || FAVOR) )
	{
		RATING=true,FAVOR=true,TAGS=true;
	}
	//printf ("JSON_OUTPUT = %d, TAGS = %d, RATING = %d, FAVOR = %d\n",JSON_OUTPUT, TAGS, RATING, FAVOR);
	if (optind >= argc)
	{
		fprintf (stderr,"%s: missing file operand\nTry \'%s -h\' for more information.\n",argv[0],argv[0]);
		return 1;
	}
	for (index = optind; index < argc; index++)
	{

		string filenow=processFileName(argv[index]);
		string nowcont=readFile(filenow);
/*
		int ssize=nowcont.size();
		for (int p=0;p<ssize;++p)
		{
			if (nowcont[p] == '\n')
				printf("\npos=%d\n",p);
			else
				printf("%c",nowcont[p]);
		}

		printf("ssize=%d\n",ssize);
		int pos = nowcont.find("xmp:Rating=\"");
		if (pos != -1)
			printf ("Rating=%c\n",nowcont[pos+12]);

		//return 0;
*/
		if  (nowcont != "")
		{
			getFileInfo(argv[index],nowcont);
		}
//                printf ("Non-option argument %s\n", argv[index]);
	}
	storeInfo(0,0,time(0),"");
	storeInfo(1,argc-optind,0,"");
	storeInfo(2,open_failed_count,0,"");
	if (JSON_OUTPUT == true)
	{
		outputJson();
	}
	return 0;
}
