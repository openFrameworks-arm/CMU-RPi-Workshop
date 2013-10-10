#!/bin/bash

echo Compiling addon examples with MAKEFLAGS=${MAKEFLAGS}
find /homes/pi/openFrameworks/addons/*/*example* -name 'Makefile' -execdir make \;


