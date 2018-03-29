#!/bin/bash
# Memery Limit Out
cat file.txt | while read line
do
    #echo $line
    temp=`tr '[0-9]' 'x' <<<"$line"`
    
    #echo $temp
    if [ "$temp"x = "(xxx) xxx-xxxx"x -o "$temp"x = "xxx-xxx-xxxx"x ]
    then
        echo $line
    fi
done

