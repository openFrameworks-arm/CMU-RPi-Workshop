#!/bin/bash

echo Compiling addon examples with MAKEFLAGS=${MAKEFLAGS}
find /home/pi/openFrameworks/addons/*/*example* -name 'Makefile' -execdir make \;


