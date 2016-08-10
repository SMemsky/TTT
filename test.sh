#/bin/bash

cd ./build/bin/

if [ $? == 0 ]; then
	./game
	cd ../
fi
