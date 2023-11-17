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
