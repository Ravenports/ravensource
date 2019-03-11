#!/bin/sh
cc -O2 -pipe -MD -MF.depend.ublio.o -MTublio.o -std=gnu99 -fstack-protector-strong -c ublio.c -o ublio.o
ar -crD libublio.a `NM='nm' NMFLAGS='' lorder ublio.o  | tsort -q` 
ranlib -D libublio.a
cc -pg  -O2 -pipe -MD -MF.depend.ublio.po -MTublio.po -std=gnu99 -fstack-protector-strong -c ublio.c -o ublio.po
ar -crD libublio_p.a `NM='nm' NMFLAGS='' lorder ublio.po  | tsort -q` 
ranlib -D libublio_p.a
cc -fpic -DPIC -g -O2 -pipe -MD -MF.depend.ublio.pico -MTublio.pico -std=gnu99 -fstack-protector-strong -c ublio.c -o ublio.pico
cc -fstack-protector-strong -shared -Wl,-x -Wl,--fatal-warnings -Wl,--warn-shared-textrel -o libublio.so.1.full -Wl,-soname,libublio.so.1  `NM='nm' NMFLAGS='' lorder ublio.pico | tsort -q` 
objcopy --only-keep-debug libublio.so.1.full libublio.so.1.debug
objcopy --strip-debug --add-gnu-debuglink=libublio.so.1.debug  libublio.so.1.full libublio.so.1
