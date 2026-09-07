#!/bin/bash

count=$#
sum=0

for number in "$@"
do
    sum=$((sum + number))
done

echo "Count: $count"

if [ "$count" -eq 0 ]; then
    echo "Average: 0"
else
    average=$(awk "BEGIN {print $sum / $count}")
    echo "Average: $average"
fi
