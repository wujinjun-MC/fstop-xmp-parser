# threads
T=4 

fifodir=~/.tmp/fifos
fifoname=${fifodir}/$$.fifo
mkdir -p $fifodir
mkfifo $fifoname
ISFAILED_FILE=$(tempfile)

SRCDIR=./src
out="fstopxmp"

cmdBuild(){
	echo Compiling "${cppname%.*}".cpp
	if ccache g++ $1 -c "${cppname%.*}".cpp -o "${cppname%.*}".o
	#ccache g++ $1 -c "${cppname%.*}".cpp -o "${cppname%.*}".o
	then
		echo Compiled "${cppname%.*}".cpp
	else
		echo Compile "${cppname%.*}".cpp failed | tee -a $ISFAILED_FILE
		return 1
		#kill $$
	fi
}

onExitScript()
{
	exit
}

# Script main start

trap 'onExitScript' SIGINT
trap 'onExitScript' SIGTERM

exec 6<>$fifoname

for i in $(seq 1 $T)
do
	echo
done >&6

for cppname in "$SRCDIR"/*.cpp
do
	read -u6
	{
		cmdBuild "$@"
		echo >&6
	}&
	
done
wait
echo "Compiled all cpp files."
if ! grep "failed" "$ISFAILED_FILE"
then
	echo "Linking"
	if ccache g++ $1 "$SRCDIR"/*.o -o "$out"
	then
		echo Generated '"'"$out"'"'
		echo Clean '*.o'
		rm -v "$SRCDIR"/*.o
	else
		echo "Linking failed"
	fi
	rm -f "$ISFAILED_FILE"
else
	echo At least 1 error occured, linking canceled.
	echo "---- error log [$ISFAILED_FILE] start ----"
	cat "$ISFAILED_FILE"
	echo "---- error log end ----"
fi
exec 6>&-
rm -f $fifoname
