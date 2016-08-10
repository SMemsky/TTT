#!/bin/bash

# Call make clean in ./src/

cd ./src/

if [ $? == 0 ]; then
	make clean
	cd ../
fi
