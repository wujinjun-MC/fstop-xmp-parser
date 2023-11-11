#include "include/main.h"

//global variables

        bool JSON_OUTPUT=false,TAGS=true,FAVOR=true,RATING=true;


int main(int argc,char *argv[])
{
        int return_code=getOptions(argc,argv);
                return return_code;
        
        return 0;
}
