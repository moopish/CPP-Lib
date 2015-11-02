#!/bin/bash

SCRIPTPATH=`pwd -P`

if [ -z "$1" ]; then
   echo "usage"

elif [ "$1" = "cd" ]; then
   exit

elif [ "$1" = "add" ]; then
   make add

elif [ "$1" = "push" ]; then
   make push

elif [ "$1" = "commit" ]; then
   make commit m="${@:2}"

elif [ "$1" = "dir" ]; then
   if [ -z "$2" ]; then
      echo "error: Need a directory name"
      exit

   elif [ $# -eq 2 ]; then
      echo "Making path ${SCRIPTPATH}/${2}"
      mkdir ${2}
      sed s/DIRNAME/$2/ template/dirmake.template > $2/makefile    

   else
      echo "error: Directory name invalid or multiple names given"
      exit
   fi

else
   echo "error: Invalid Option!"
   exec $0
fi
