#!/bin/bash

echo "Enter first number:"
read p
echo "Enter second number:"
read q

echo "Choose operation(+,-,*,/):"
read op

if [ "$op" == "+" ]; then
    result=$((p + q))
elif [ "$op" == "-" ]; then
    result=$((p - q))
elif [ "$op" == "*" ]; then
    result=$((p * q))
elif [" $op" == "/" ]; then
    result=$((p / q))
else
    echo "Invalid operation"
    exit 1
fi
echo "The result is : $result"