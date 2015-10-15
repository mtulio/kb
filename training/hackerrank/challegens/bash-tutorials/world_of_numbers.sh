#!/bin/bash
read X
read Y
if [ $X -lt -100 ] ||
    [ $X -gt 100 ] ||
    [ $Y -lt -100 ] ||
    [ $Y -gt 100 ] ||
    [ $Y -eq 0 ]
    then
      exit 1
    else
      echo "$X+($Y)" |bc
      echo "$X-($Y)" |bc
      echo "$X*($Y)" |bc
      echo "scale=0;$X/($Y)" |bc
    fi

