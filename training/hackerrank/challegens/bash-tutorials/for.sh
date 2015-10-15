#!/bin/bash

for ((X=0;X<=99;X++))
do
  if [ `expr $X % 2` -ne 0 ]; then
   echo $X
  fi
done
