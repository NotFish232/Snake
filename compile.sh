#!/bin/bash

set -e

rm -f ./bin/*

size() {
	echo $(du -hs $1 | cut -f1)
}

start=$SECONDS

for file in ./src/*.cpp; do
	base=$(basename $file .cpp)
	g++ -c $file -o "./bin/$base.o"
	echo "Compiled \`$base.cpp\` ($(size ./bin/$base.o))"
done

g++ main.cpp ./bin/*.o ../utils/bin/lib.o -o "./bin/main.out" -l sfml-system -l sfml-graphics -l sfml-window

end=$SECONDS

echo "Total binary size: $(size ./bin/main.out)"
echo "Compile time: $((end - start)) seconds"