#!/bin/bash

SCRIPTPATH=`pwd -P`
BACKSLASH=\\

if [ -z "$1" ]; then
   echo "usage"

elif [ "$1" = "cd" ]; then
   exit

elif [ "$1" = "add" ]; then
   git add *

elif [ "$1" = "push" ]; then
   git push origin master

elif [ "$1" = "commit" ]; then
   make commit m="get\ working"

elif [ "$1" = "make" ]; then
   make -s -f makefile -C main/

elif [ "$1" = "clean" ]; then
   make clean

elif [ "$1" = "dir" ]; then
   if [ -z "$2" ]; then
      echo "error: Need a directory name"
      exit

   elif [ $# -eq 2 ]; then
      echo "Making path ${SCRIPTPATH}/main/${2}"
      mkdir main/${2}
      sed s/DIRNAME/$2/ template/dirmake.template > main/$2/makefile    

   else
      echo "error: Directory name invalid or multiple names given"
      exit
   fi

else
   echo "error: Invalid Option!"
   exec $0
fi
