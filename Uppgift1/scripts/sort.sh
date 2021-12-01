#!/bin/bash

# Sort all .txt files in data dir with main.out program
for file in ../data/*.txt
do
    ../out/main.out $file
done
