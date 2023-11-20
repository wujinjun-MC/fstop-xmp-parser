#include "include/printHelp.h"

const char HELP_TEXT[]="fstopxmp -j [-T TABS] [-m METHOD] [-w THREADS] [-L MAX_FILE_COUNT] [-i] [-t] [-r] [-f] [FILE]...\n\
Options:\n\
    -j                   JSON output\n\
    -T TABS              Enable JSON pretty output with TABS tabs for each indentation level.\n\
    -m METHOD            Choose getFileInfo() method, default is 3. The avaliable METHODs are:\n\
                             1    Get \"tags\" using regex, get \"favorite\" and \"rating\" using \"substr()\"\n\
                             2    Get \"tags\",\"favorite\",\"rating\" using \"substr()\"\n\
                             3    Get \"tags\" using both of \"substr()\" and \"str[pos]\", get \"favorite\" and \"rating\" using \"str[pos]\"\n\
                             (Tested efficiency: 3>2>1)\n\
    -w THREADS           Worker threads, an integer ranging from 1 to 128.\n\
    -L MAX_FILE_COUNT    Limit file count to MAX_FILE_COUNT\n\
    -i                   Read from file list. Treat FILE as newline-seperated file name(s). If \"-\" is given, read from standard input.\n\
    -t, -r, -f:\n\
                         -t    Include tags\n\
                         -r    Include ratings\n\
                         -f    Include favorites\n\
                         If those are not given, Include all of them.\n\
    FILE:\n\
                         1)    If -i is not given, FILE are *.xmp Files, or other files with other suffix but have their *.xmp files.\n\
                         2)    If -i is given, FILE are newline-seperated file name(s)(See option \"-i\" above).\n\
";

void printHelp()
{
    printf("%s",HELP_TEXT);
    return;
}

