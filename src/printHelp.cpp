#include "include/printHelp.h"

const char HELP_TEXT[]="fstopxmp -j [-T TABS] [-m METHOD] [-w THREADS] [-L MAX_FILE_COUNT] [-i] [-t] [-r] [-f] [FILE]...\n\
Options:\n\
    -j                   JSON output\n\
    -T TABS              Enable JSON pretty output with TABS tabs for each indentation level.\n\
    -m METHOD            Choose getFileInfo() method, default is 3. The avaliable METHODs are:\n\
                             1    Get \"tags\" using regex, get \"favorite\" and \"rating\" using \"substr()\"\n\
                             2    Get \"tags\",\"favorite\",\"rating\" using \"substr()\"\n\
                             3    Get \"tags\" using both of \"substr()\" and \"str[pos]\", get \"favorite\" and \"rating\" using \"str[pos]\"\n\\n\
                             (Tested efficiency: 3>2>1)\n\
    -w THREADS           Worker threads, an integer ranging from 1 to 128. Implies any reverse features.\n\
    -L MAX_FILE_COUNT    Limit file count to MAX_FILE_COUNT\n\
    -i                   Read from file list. Treat FILE as newline-seperated file name(s). If \"-\" is given, read from standard input.\n\
    -o OUTPUT_OPTIONS    Use the specified output options. The OUTPUT_OPTIONS argument is a comma-separated list.\n\
    The avaliable OUTPUT_OPTIONS are: \n\
                             t    Include \"tags\"\n\
                             r    Inlcude \"rating\"\n\
                             f    Include \"favorite\"\n\
                             rt   Include \"tags\"(reverse), implies \"-w\"\n\
                             rr   Include \"rating\"(reverse), implies \"-w\"\n\
                             rf   Include \"favorite\"(reverse), implies \"-w\"\n\
                             i    exclude all of \"info\"\n\
                         If OUTPUT_OPTIONS is \"\" or not set, set to default \"r,t,f\".\n\
    FILE:\n\
                         1)    If -i is not given, FILE are *.xmp Files, or other files with other suffix but have their *.xmp files.\n\
                         2)    If -i is given, FILE are newline-seperated file name(s)(See option \"-i\" above).\n\
";

void printHelp()
{
    printf("%s",HELP_TEXT);
    return;
}

