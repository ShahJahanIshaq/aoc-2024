#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <part-number>"
    exit 1
fi

part_number=$1

if ! [[ $part_number =~ ^[12]$ ]]; then
    echo "Error: Part number must be 1 or 2."
    exit 3
fi

make all

executable="part${part_number}.o"

if [ ! -f "$executable" ]; then
    echo "Error: Executable $executable does not exist."
    exit 4
fi

./$executable < input.txt > output.txt

make clean
code output.txt