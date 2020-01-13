#!/bin/bash
cd $(pwd)
if [[ -f input.txt ]]; then
rm input.txt
fi
for ((i=0;i<120;i++))
do
echo $((1 + RANDOM % 500)) >> input.txt
done
