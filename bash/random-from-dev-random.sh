#!/bin/bash

echo "Enter the number of random bytes you require:"
read n
echo $(head -c $n /dev/random | base64)
