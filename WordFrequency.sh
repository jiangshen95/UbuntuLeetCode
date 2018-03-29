#!/bin/bash
# can't solve this problem
declare -A map=()
cat words.txt | while read line
do
    words=($line)
    for word in ${words[@]}
    do
        echo "1 $word"
        is_in=0
        declare -p map
        for key in ${!map[@]}
        do
            if [ "$key"x = "$word"x ]
            then
                echo "2 $word"
                is_in=1
                #map[$key]=${map[$key]}+1
                let map[$key]+=1
                break
            fi
        done
        if [ $is_in == 0 ]
        then
            map[$word]=1
        fi
    done
done
declare -p map
for key in ${!map[@]}
do
    #echo $key
    echo "$key $map[key]"
done
