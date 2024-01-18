# fstop-xmp-parser

Read/Write tags, rating and favorite infomation for .xmp file generated by F-Stop Gallery APP(Android).

## Features

* Read tags, rating(developing), favorite(developing) from .xmp files using substr() or str\[pos\] method
* JSON output
* Multi thread support
* Reverse list(list file names under tags/rating/favorite) support
* ...

## Usage

```
fstopxmp -j [-T TABS] [-m METHOD] [-w THREADS] [-L MAX_FILE_COUNT] [-i] [-t] [-r] [-f] [FILE]...
Options:
    -j                   JSON output
    -T TABS              Enable JSON pretty output with TABS tabs for each indentation level.
    -m METHOD            Choose getFileInfo() method, default is 2. The avaliable METHODs are:
                             1    Get "tags","favorite","rating" using "substr()"
                             2    Get "tags" using both of "substr()" and "str[pos]", get "favorite" and "rating" using "str[pos]"
                             (Tested efficiency: 2>1)
    -w THREADS           Worker threads, an integer ranging from 1 to 128. Implies any reverse features.
    -L MAX_FILE_COUNT    Limit file count to MAX_FILE_COUNT
    -i                   Read from file list. Treat FILE as newline-seperated file name(s). If "-" is given, read from standard input.
    -o OUTPUT_OPTIONS    Use the specified output options. The OUTPUT_OPTIONS argument is a comma-separated list.
    The avaliable OUTPUT_OPTIONS are: 
                             t    Include "tags"
                             r    Inlcude "rating"
                             f    Include "favorite"
                             rt   Include "tags"(reverse), implies "-w"
                             rr   Include "rating"(reverse), implies "-w"
                             rf   Include "favorite"(reverse), implies "-w"
                             i    exclude all of "info"
                         If OUTPUT_OPTIONS is "" or not set, set to default "r,t,f".
    FILE:
                         1)    If -i is not given, FILE are *.xmp Files, or other files with other suffix but have their *.xmp files.
                         2)    If -i is given, FILE are newline-seperated file name(s)(See option "-i" above).
```

## Guide to compile

### Linux

* Dependencies: 
    * Building: 
        * ccache
        * gcc
        * clang
* Script: 
    * bash
```
tar xvf fstop-xmp-parser.tar.gz
cd fstop-xmp-parser
./build.sh -O2
```
## Goals

* Method
    * Add xml\_reader method
* Features
    * Add comparison mode. Input previous json file and scan file and check wether they change or not.
    * Add status counter
    * Add interactive mode to directly view and edit info, or preview media in your terminal, or open in x11 desktop
    * Support YAML output
    * support user-friendly(vanilla) output
    * Edit tags, rating and favorite then write to .xmp file
    * Write to file seperately
    * Support verbose log
    * Add more exit status
    * Support long options
* Document
    * Add manpage
