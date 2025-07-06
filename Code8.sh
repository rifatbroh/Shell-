#!/bin/bash

echo "Enter the first number: "
read p
echo "Enter the second number: "
read q

echo "Bitwise AND: $((p & q))"
echo "Bitwise OR: $((p | q))"
