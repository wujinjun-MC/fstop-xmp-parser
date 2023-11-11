SRCDIR=./src
out="fstopxmp"

cmdBuild(){
        echo Compiling "${cppname%.*}".cpp
        ccache g++ $1 -c "${cppname%.*}".cpp -o "${cppname%.*}".o
        echo Compiled "${cppname%.*}".cpp
}

for cppname in "$SRCDIR"/*.cpp
do
        cmdBuild "$@" &
done

wait
echo "Compiled all cpp files."
echo "Linking"
ccache g++ "$SRCDIR"/*.o -o "$out"

echo Generated '"'"$out"'"'
echo Clean '*.o'
rm -v "$SRCDIR"/*.o
