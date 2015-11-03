#!/bin/bash

#parameter 1 is the file
#parameter 2 is the in file path
#parameter 3 is the out file path
#parameter 4 is the file type

DEPENDS=

if [ $# -eq 4 ]; then
  
   EMP= 
   $EMP > .dep.temp

   while read -r line 
   do
      t_line=${line#*\"}
      DEPENDS="${DEPENDS} ${t_line%\"*}"
     
      echo $t_line
      echo $DEPENDS
   done < <(grep \#include.*\" $2/$1)
  
   echo $DEPENDS 
   case $4 in
      c)
         FORMAT=c.make
      ;;
      cpp)
         FORMAT=cpp.make
      ;;
      h)
         FORMAT=h.make
      ;;
      *)
         echo Fail with $0 $@
         echo File type not accepted
      ;;
   esac

   sed -e s/FILE/$1/g -e s#FPATH#$2#g -e s/OUT/$3/g -e s/DEPENDS/"$DEPENDS"/g < $FORMAT > .${1}.dept
else
   echo Fail with $0 $@
fi

