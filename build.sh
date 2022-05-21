#!/bin/bash
set -e
mkdir -p `pwd`/build/
mkdir -p `pwd`/bin/
mkdir -p `pwd`/lib/
cd `pwd`/build &&
	cmake .. &&
	make
cd ..
cp -r `pwd`/src/include `pwd`/lib