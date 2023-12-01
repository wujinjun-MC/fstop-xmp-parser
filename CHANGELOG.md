# Version 1.4
* README.md
    * Fixed word error in line 67
        * "recursive" -> "reverse"
* Add
    * Added reverse list: list file names under tags, favorite or ratings(Under .items).
        * Early development
            * Known bug: Multi thread "-w" causes random loss of file names in reverse list.
* Fix
    * Blank file or blank mid-processed json will no longer cause final json loss
* Optimize
    * No longer pass thread ID to each tasks
* Readme.md
    * Changed './build.sh -O2' to './buildsh "-flto -O2"'
* ./build.sh
    * Removed default '-flto'
* ./docs/EXIT_CODE.md
    * Added exit code "3" in docs/EXIT_CODE.md
        * Now exit codes:

| Exit_code | Description | Example |
| 0 | Normal exit | ./fstopxmp -j test/test1.xmp |
| 1 | No file opernd | - |
| 2 | Option resolve error | - |
| 3 | Options or option arguments conlicted | ./fstopxmp -j -o rt -w 4 -i filelist.txt |

# Version 1.3
* Add
    * Added file list support(-i)
* Edit
    * Changed per-run-time info in json
* ./build.sh
    * Enabled "-flto" to optimize linking.
    * Now it cancel linking when compiling is not passed

# Version 1.2
* Add
    * Added multi thread support(-w THREADS)
    * Support max file count limit(-L MAX\_FILE\_COUNT)
* ./docs/EXIT_CODE.md
    * Added docs/EXIT_CODE.md
        * Now exit codes:

| Exit_code | Description |
| 0 | Normal exit |
| 1 | No file opernd |
| 2 | Option resolve error |

* ./build.sh
    * SUpport limit compile thread


# Version 1.1
* Add
    * Added more methods/algorithms to resolve data
    * Added per-run-time info to JSON: last\_update\_time\_stamp,file\_count,file\_error\_count
    * Added command-line help(-h)
* Edit
    * Changed JSON struture
        * Now per file info stores under 'files' and per-run-time info stores under 'info'
* ./README.md
    * Added full usage

# Version 1.0.1
* Add
    * Added rating, favorite information support
* Fix
    * Fixed illegal null array
* Build
	* build.sh now added '&' to command support multi thread compile

# Version 1.0
* Initial release
