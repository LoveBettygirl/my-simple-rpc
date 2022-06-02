#!/bin/bash
cp -r `pwd`/lib/mysimplerpc /usr/local/include
cp `pwd`/lib/libmysimplerpc.a /usr/local/lib
ldconfig /usr/local/lib