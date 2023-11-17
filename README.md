# fstop-xmp-parser

Read/Write tags, rating and favorite infomation for .xmp file generated by F-stop APP(Android).

## Features

* Read tags, rating(developing), favorite(developing) from .xmp files using regex, substr() or str\[pos\].
* JSON output
* ...

## Usage

```
fstopxmp -j [-m METHOD] [-t] [-r] [-f] [FILE]...
Options:
	-j: JSON output
	-m METHOD: Choose getFileInfo() method, default is 2.
		1: Get "tags" using regex, get "favorite" and "rating" using "substr()"
		2: Get "tags","favorite","rating" using "substr()"
		3: Get "tags" using both of "substr()" and "str[pos]", get "favorite" and "rating" using "str[pos]"
		Efficiency: 3>2>1
	-t, -r, -f:	
		-t: Include tags
		-r: Include ratings
		-f: Include favorites
		If those are not given,Include all of them.
	FILE: *.xmp files, or other files which have their *.xmp files in the same path.
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

* Bug fix
    * Get favorite and rating not currently
* Method
    * Add xml\_reader method
* Features
    * Support YAML output
    * Support JSON pretty output
    * support user-friendly(vanilla) output
    * Edit tags, rating and favorite then write to .xmp file
    * Write to file seperately
    * Support verbose log
    * Add more exit status
    * Direct read file list from pipe/stdin
    * Support long options
* Document
    * Add manpage
    * Add exit status document
