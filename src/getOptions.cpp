//reference: https://www.codenong.com/18079340/

#include "include/getOptions.h"
using namespace std;

int getOptions (int argc, char **argv)
{
        char *cvalue = NULL;
        int index;
        int op;

        opterr = 0;

        while ((op = getopt (argc, argv,"hjtrf")) != -1)
        {
                switch (op)
                {
                        case 'h':
                                printf(R"(Still in early development
Usage: %s -j [-t] [-r] [-r] [FILE]...
)",
                                argv[0]);
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
                        case '?':
                                if (optopt == 'c')
                                {
                                        fprintf (stderr,"Option -%c requires an argument.\
", optopt);
                                }
                                else if (isprint (optopt))
                                {
                                        fprintf (stderr,"Unknown option `-%c'.\
", optopt);
                                }
                                else
                                {
                                        fprintf (stderr,"Unknown option character `\\\\x%x'.",optopt);
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
                fprintf (stderr,"Need to specific at least 1 file\n");
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
                if (JSON_OUTPUT == true)
                {
                        if  (nowcont != "")
                        {
                                getFileInfoJson(argv[index],nowcont);
                        }
                }
//                printf ("Non-option argument %s\n", argv[index]);
        }
        if (JSON_OUTPUT == true)
        {
                outputJson();
        }
        return 0;
}