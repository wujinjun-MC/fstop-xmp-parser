//reference: https://www.codenong.com/18079340/

#include "include/getOptions.h"
using namespace std;

int getOptions (int argc, char **argv)
{
        char *cvalue = NULL;
        int index;
        int op;

        opterr = 0;

        while ((op = getopt (argc, argv,"jtfr:")) != -1)
        {
                switch (op)
                {
                        case 'j':
                                JSON_OUTPUT = true;
                                break;
                        case 't':
                                TAGS = true;
                                break;
                        case 'r':
                                RATING = true;
                                break;
                        case 'c':
                                cvalue = optarg;
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
//        printf ("JSON_OUTPUT = %d, TAGS = %d, RATING = %d, FAVOR = %d\n",JSON_OUTPUT, TAGS, RATING, FAVOR);
        if (optind >= argc)
        {
                fprintf (stderr,"Need to specific at least 1 file\n");
                return 1;
        }
        for (index = optind; index < argc; index++)
        {
                
                string filenow=processFileName(argv[index]);
                string nowcont=readFile(filenow);
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