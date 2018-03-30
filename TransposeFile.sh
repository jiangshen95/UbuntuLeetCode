#!/bin/bash
cat file.txt | awk '{for (i=1;i<=NF;i++)  {if(D[i]) {D[i]=D[i]" "$i} else {D[i]=$i} } } END {for(i in D) {print D[i]}}'
awk '{for (i=1;i<=NF;i++)  {if(NR==1) {D[i]=$i} else {D[i]=D[i]" "$i} } } END {for(i in D) {print D[i]}}' file.txt
#cat file.txt | awk 'NR==2{print $2}'
