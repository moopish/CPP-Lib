#!/bin/bash

#parameter 1 is the file
#parameter 2 is the in file path
#parameter 3 is the out file path
#parameter 4 is the file type

DEPENDS=
CDIR=${0%/*}

echo $CDIR

if [ $# -eq 4 ]; then

   while read -r line 
   do
      t_line=${line#*\"}
      DEPENDS="${DEPENDS} ${t_line%\"*}"
     
      echo $t_line
      echo $DEPENDS
   done < <(grep \#include.*\" ${2}/${1}.${4})
  
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

   #sed -e s#FILE#$1#g -e s#FPATH#$2#g -e s#OUT#$3#g -e s#DEPENDS#$(DEPENDS)#g < ${CDIR}/${FORMAT} > ${CDIR}.${1}.dept

  #/"" > ${OUT}/${1}.dept
   while read -r line
   do
      awk '{ gsub("FILE",$1,$line);
             gsub("FPATH",$2,$line);
             gsub("OUT",$3,$line);
             gsub("DEPENDS",$DEPENDS,$line);
             print $line }' 
   done < ${CDIR}/${FORMAT}

elif [ $# -eq 3 ]; then
   $0 ${1##*/} ${1%/*} $2 $3

elif [ $# -eq 2 ]; then
   $0 ${1%.*} $2 ${1##*.}

else
   echo Fail with $0 $@
fi

