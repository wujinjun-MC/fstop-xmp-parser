//reference: https://www.codenong.com/18079340/

#include "include/getOptions.h"

using namespace std;

static bool hasOption_o=false;

char fnames[500000][257];
const char (*fnamesp)[257]=fnames;

thread threads[129];

inline void processOUTPUTOPTIONS(char *o)
{
	int olen=strlen(o);
	//printf ("outopts.len=%d\noutopts=%s\n",olen,o);
	if (!olen)
	{
		hasOption_o=false;
		return;
	}
	int opos=0;
	while (opos < olen)
	{
		
		//printf ("pos=%d\n%c\n",opos,o[opos]);
		switch(o[opos++])
		{
			case 'r':
				switch(o[opos++])
				{
					
					case 't':
						//printf ("pos=%d\n%d\n",opos-1,o[opos-1]);
						switch(o[opos++])
						{
							case ',':
							case 0:
								//printf ("pos=%d\n%d\n",opos-1,o[opos-1]);
								REVERSE_TAGS=true;
								break;
						}
						break;
					case 'f':
						switch(o[opos++])
						{
							case ',':
							case 0:
								REVERSE_FAVOR=true;
								break;
						}
						break;
					case 'r':
						switch(o[opos++])
						{
							case ',':
							case 0:
								REVERSE_RATING=true;
								break;
						}
						break;
					case ',':
							case 0:
						RATING=true;
						break;
				}
				break;
			case 'f':
				switch(o[opos++])
				{
					case ',':
					case 0:
						FAVOR=true;
						break;
				}
				break;
			case 't':
				switch(o[opos++])
				{
					case ',':
					case 0:
						TAGS=true;
						break;
				}
				break;
			case 'i':
				switch(o[opos++])
				{
					case ',':
					case 0:
						INFO=false;
						break;
				}
				break;
			default:
				break;
		}
	}
	return;
}

int getOptions (int argc, char *argv[])
{
	//char *cvalue = NULL;
	int index;
	int op;

	opterr = 0;

	while ((op = getopt (argc, argv,"hjo:T:m:w:L:i")) != -1)
	{
	    //printf("start getopt()\n");
		switch (op)
		{
			case 'h':
/*
				printf(R"(Still in early development
)");
*/
				printHelp();
				return 0;
			case 'j':
				JSON_OUTPUT = true;
				break;
			case 'o':
				//printf("-o %s\n",optarg);
				hasOption_o=true;
				processOUTPUTOPTIONS(optarg);
				break;
			case 'T':
				TABS = atoi(optarg);
				break;
			case 'm':
				METHOD = atoi(optarg);
				if ( METHOD > 2 || METHOD < 1 )
				{
					fprintf ( stderr,"Invalid METHOD: METHOD is an integer ranging from 1 to 2\n");
					return 2;
				}
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
			case 'i':
				READ_FILE_LIST = true;
				break;
			case '?':
				if (optopt == 'T' || optopt == 'm' || optopt == 'w' || optopt == 'L' || optopt == 'o' )
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
	if ( threads_num > 1 && ( REVERSE_RATING || REVERSE_TAGS || REVERSE_FAVOR ) )
	{
		fprintf(stderr,"Conflicted options or option arguments: \"Multi thread\" feature implies \"Reverse info\" feature.\n");
		return 3;
	}
	/*
	for (int i=0;i<argc;++i)
		printf("argv[%d]=%s\n",i,argv[i]);
	*/
	if (!hasOption_o)
	{
		RATING=true,FAVOR=true,TAGS=true,INFO=true;
	}
	
	//printf ("JSON_OUTPUT = %d, TAGS = %d, RATING = %d, FAVOR = %d\n",JSON_OUTPUT, TAGS, RATING, FAVOR);
	if (optind >= argc)
	{
		fprintf (stderr,"%s: missing file operand\nTry \'%s -h\' for more information.\n",argv[0],argv[0]);
		return 1;
	}
	if (READ_FILE_LIST)
	{
		FILE_LIST_COUNT=optind-argc;
		for (int i=optind;i<argc;++i)
		{
			if ( MAX_FILE_COUNT > 0 && MAX_FILE_COUNT < FILE_COUNT+1 )
			{
				break;
			}
			readFileList(argv[i]);
		}
		if ( FILE_COUNT < threads_num )
		{
			threads_num=FILE_COUNT;
		}
		if ( threads_num > 1 )
		{
			int step = FILE_COUNT / threads_num;
			for (int i=0;i<threads_num;++i)
			{
				int st=i*step+1;
				int end=(i+1)*step+1;
				if ( i == threads_num-1 )
				{
					end = FILE_COUNT+1;
				}
				//fprintf(stderr,"st=%d,end=%d\n",st,end);
				threads[i] = thread(runThread2,i,st,end);
			}
			for (int i = 0; i < threads_num; ++i)
			{
				threads[i].join();
			}
		}
		else
		{
			runThread2(0,1,FILE_COUNT+1);
		}
	}
	else
	{
		if ( MAX_FILE_COUNT > 0 && MAX_FILE_COUNT < argc-optind )
		{
			argc = MAX_FILE_COUNT + optind;
		}
		//printf ("argc=%d,argc-optind=%d\n",argc,argc-optind);
	
		//argc=optind+3;
		if ( argc-optind < threads_num )
		{
			threads_num=argc-optind;
		}
		if ( INFO )
		{
			storeInfo(1,argc-optind,0,"");
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
				threads[i] = thread(runThread,i,argv,st,end);
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
			runThread(0,argv,optind,argc);
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
	}
	//storeInfo(2,open_failed_count,0,"");
	//printf("INFO=%d\n",INFO);
	if ( INFO )
	{
		storeInfo(4,0,0,"");
		storeInfo(3,threads_num,0,"");
		storeInfo(0,0,time(0),"");
		if ( READ_FILE_LIST )
		{
			storeInfo(1,FILE_COUNT,0,"");
		}
		
	}
		if (JSON_OUTPUT == true)
	{
		outputJson(TABS);
	}
	return 0;
}
