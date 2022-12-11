#!/bin/sh

while read line; do
sed -i'' -e 's|{{TAR}} -xf|env LANG=en_US.UTF-8 {{TAR}} -xf|' /home/marino/ravensource/${line}/specification
done < php82.list
