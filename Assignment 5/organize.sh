#!/bin/bash

# organize -t tarDir -o orgDir <extList>

while getopts ":t:o:" option
do
   case ${option} 
       in
       t)
           tarDir=${OPTARG};;
       o)
           orgDir=${OPTARG};;
       *)
           echo $option;;
   esac
done

shift $((OPTIND-1))

extList=$@

#if extension in argument is not present
if [ -z "$extList" ]; then
    echo "invalid parameters"
    exit 1
fi

# tarDir
if [ -z "$tarDir" ]; then
   tarDir=$PWD
fi

#creating orgDir if missing and if orgDir is not existed
if [[ -z $orgDir ]] 
then
  orgDir=${PWD}/orgDir
  $(mkdir $orgDir) 
elif [[ -d $orgDir && -w $orgDir ]]
then
  orgDir=$orgDir
else
    echo "file has no write permissions or doesnt exist"
    exit 1
fi

#copying files and making tar file at orgDir and delete files at tarDir
for e in $extList; do
   file="$e.tar"
   c=1
   while [ -f "$orgDir/$file" ]; do
       file="${e}_$c.tar"

       c=$((c + 1))
   done
   find "$tarDir" -type f -name "*.$e" -exec tar cf "$orgDir/$file" {} +
   find "$tarDir" -type f -name "*.$e" -delete 
done
