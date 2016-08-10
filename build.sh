#!/bin/bash

# Simply starts a makefile in ./src/

cd ./src/

if [ $? == 0 ]; then
	make
	cd ../
fi
