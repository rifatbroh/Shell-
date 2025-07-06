#!/bin/bash

echo "Enter a random number: "
read p

if ((p%2 == 0))
then echo "$p is Even number"
else echo "$p is Odd number"
fi