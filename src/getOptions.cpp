//reference: https://www.codenong.com/18079340/

#include "include/getOptions.h"

using namespace std;

thread threads[129];

int getOptions (int argc, char **argv)
{
	char *cvalue = NULL;
	int index;
	int op;

	opterr = 0;

	while ((op = getopt (argc, argv,"hjtrfm:w:L:")) != -1)
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
			case 'w':
				threads_num = atoi(optarg);
				if ( threads_num > 129 || threads_num < 1 )
				{
					fprintf ( stderr,"Invalid THREADS: THREADS is an integer ranging from 1 to 128\n");
					return 2;
				}
				break;
			case 'L':
				MAX_FILE_COUNT = atoi(optarg);
				break;
			case '?':
				if (optopt == 'w' || optopt == 'm')
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
	if ( MAX_FILE_COUNT > 0 && MAX_FILE_COUNT < argc-optind )
	{
		argc = MAX_FILE_COUNT + optind;
	}
	storeInfo(0,0,time(0),"");
	storeInfo(1,argc-optind,0,"");

	//argc=optind+3;
	if ( argc-optind < threads_num )
	{
		threads_num=argc-optind;
	}
	//fprintf(stderr,"argc-optind=%d,threads_num=%d\n",argc-optind,threads_num);
	if ( threads_num > 1 )
	{
		int data_size = argc-optind;
		int step = data_size / threads_num;
		//fprintf(stderr,"data_size=%d,step=%d\n",data_size,step);
		for (int i=0;i<threads_num;++i)
		{
			int st=i*step+optind;
			int end=(i+1)*step+optind;
			if ( i == threads_num-1 )
			{
				end = data_size+optind;
			}
			//fprintf(stderr,"st=%d,end=%d\n",st,end);
			threads[i] = thread(runThread,argv,i,st,end);
		}
		//threads[threads_num-1] = thread(runThread,argv,threads_num-1,(threads_num-1)*step+optind,argc-1);
		//printf("threads[%d] = thread(runThread,argv,%d,%d,%d);\n",threads_num-1,threads_num-1,(threads_num-1)*step+optind,argc-1);
		for (int i = 0; i < threads_num; ++i)
		{
			//printf("threads=%d\n",threads_num);
			threads[i].join();
		}
	}
	else
	{
		runThread(argv,0,optind,argc);
/*
		for (index = optind; index < argc; index++)
		{
			runTask(argv[index],0);
//
			string filenow=processFileName(argv[index]);
			string nowcont=readFile(filenow);
			if  (nowcont != "")
			{
				getFileInfo(argv[index],nowcont);
			}
//
		}
*/
	}
	//storeInfo(2,open_failed_count,0,"");
	storeInfo(3,threads_num,0,"");
	if (JSON_OUTPUT == true)
	{
		outputJson();
	}
	return 0;
}
