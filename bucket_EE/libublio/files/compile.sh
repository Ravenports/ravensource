#!/bin/sh
cc ${CFLAGS} -MD -MF.depend.ublio.o -MTublio.o -c ublio.c -o ublio.o
ar -crD libublio.a `NM='nm' NMFLAGS='' lorder ublio.o  | tsort -q` 
ranlib -D libublio.a
cc -p  ${CFLAGS} -MD -MF.depend.ublio.po -MTublio.po -c ublio.c -o ublio.po
ar -crD libublio_p.a `NM='nm' NMFLAGS='' lorder ublio.po  | tsort -q` 
ranlib -D libublio_p.a
cc -fpic -DPIC ${CFLAGS} -MD -MF.depend.ublio.pico -MTublio.pico -c ublio.c -o ublio.pico
cc -shared ${CFLAGS} -Wl,-x -Wl,--fatal-warnings -Wl,--warn-shared-textrel -o libublio.so.1.full -Wl,-soname,libublio.so.1  `NM='nm' NMFLAGS='' lorder ublio.pico | tsort -q` 
objcopy --only-keep-debug libublio.so.1.full libublio.so.1.debug
objcopy --strip-debug --add-gnu-debuglink=libublio.so.1.debug  libublio.so.1.full libublio.so.1
