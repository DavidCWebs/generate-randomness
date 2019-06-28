#!/bin/bash

echo "Enter the number of random bytes you require per key:"
read nBytes

echo "Enter the number of random keys required:"
read nKeys

for ((i=0; i<$nKeys; i++)) do echo $(head -c $nBytes /dev/urandom | base64); done

#TODO: provide an option to write to file

