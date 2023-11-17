T=4 # threads
fifodir=~/.tmp/fifos
fifoname=${fifodir}/$$.fifo
mkdir -p $fifodir
mkfifo $fifoname


SRCDIR=./src
out="fstopxmp"

cmdBuild(){
        echo Compiling "${cppname%.*}".cpp
        ccache g++ $1 -c "${cppname%.*}".cpp -o "${cppname%.*}".o
        echo Compiled "${cppname%.*}".cpp
}

exec 6<>$fifoname

for ((i=0;i<${T};i++))
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
echo "Linking"
ccache g++ "$SRCDIR"/*.o -o "$out"

echo Generated '"'"$out"'"'
echo Clean '*.o'
rm -v "$SRCDIR"/*.o
exec 6>&-
rm -f $fifoname
