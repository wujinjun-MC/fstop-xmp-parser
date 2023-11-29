# fstop-xmp-parser

Read/Write tags, rating and favorite infomation for .xmp file generated by F-stop APP(Android).

## Features

* Read tags, rating(developing), favorite(developing) from .xmp files using regex, substr() or str\[pos\] method
* JSON output
* Multi thread support
* ...

## Usage

```
fstopxmp -j [-T TABS] [-m METHOD] [-w THREADS] [-L MAX_FILE_COUNT] [-i] [-t] [-r] [-f] [FILE]...
Options:
    -j                   JSON output
    -T TABS              Enable JSON pretty output with TABS tabs for each indentation level.
    -m METHOD            Choose getFileInfo() method, default is 3. The avaliable METHODs are:
                             1    Get "tags" using regex, get "favorite" and "rating" using "substr()"
                             2    Get "tags","favorite","rating" using "substr()"
                             3    Get "tags" using both of "substr()" and "str[pos]", get "favorite" and "rating" using "str[pos]"
                             (Tested efficiency: 3>2>1)
    -w THREADS           Worker threads, an integer ranging from 1 to 128.
    -L MAX_FILE_COUNT    Limit file count to MAX_FILE_COUNT
    -i                   Read from file list. Treat FILE as newline-seperated file name(s). If "-" is given, read from standard input.
    -t, -r, -f:
                         -t    Include tags
                         -r    Include ratings
                         -f    Include favorites
                         If those are not given, Include all of them.
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
    * \[JSON\]Add tags, rating and favorite pool(simply list them)
    * Add status counter
    * Add interactive mode to directly view and edit info, or preview media in your terminal, or open in x11 desktop
    * \[JSON\]Add reverse output(list tags, rating and favorite and file names are under them)
    * Support YAML output
    * support user-friendly(vanilla) output
    * Edit tags, rating and favorite then write to .xmp file
    * Write to file seperately
    * Support verbose log
    * Add more exit status
    * Support long options
* Document
    * Add manpage
