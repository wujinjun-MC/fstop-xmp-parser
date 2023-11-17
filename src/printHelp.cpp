#include "include/printHelp.h"

char help[]="fstopxmp -j [-m METHOD] [-w THREADS] [-t] [-r] [-f] [FILE]...\n\
Options:\n\
    -j: JSON output\n\
    -m METHOD: Choose getFileInfo() method, default is 3.\n\
        1: Get \"tags\" using regex, get \"favorite\" and \"rating\" using \"substr()\"\n\
        2: Get \"tags\",\"favorite\",\"rating\" using \"substr()\"\n\
        3: Get \"tags\" using both of \"substr()\" and \"str[pos]\", get \"favorite\" and \"rating\" using \"str[pos]\"\n\
        Efficiency: 3>2>1\n\
    -w THREADS: Worker threads, an integer ranging from 1 to 128.\n\
    -L MAX_FILE_COUNT: Limit file count to MAX_FILE_COUNT\n\
    -t, -r, -f:    \n\
        -t: Include tags\n\
        -r: Include ratings\n\
        -f: Include favorites\n\
        If those are not given,Include all of them.\n\
    FILE: *.xmp Files, or other files with other suffix but have their *.xmp files.\n\
";

void printHelp()
{
	printf("%s",help);
	return;
}

