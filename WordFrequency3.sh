#!/bin/bash
#cat words.txt | awk '{ for (i=1; i<=NF; i++) { ++D[$i]; } } END { for (i in D) { print i, D[i] } } ' | sort -nr -k 2
awk '{ for (i=1; i<=NF; i++) { ++D[$i]; } } END { for (i in D) { print i, D[i] } } ' words.txt | sort -nr -k 2
