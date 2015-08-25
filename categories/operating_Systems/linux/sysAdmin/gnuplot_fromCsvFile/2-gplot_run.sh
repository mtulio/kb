#!/bin/bash

# 2-gplot_run.sh - Run gnuplot

if [ ! -f data.csv ]; then
  echo "#% ERRO - Data file [data.csv] not found. Already you ran script '1-get_connection_stats.sh' to generete it?"
  exit 1;
fi

if [ ! -f gplot_generateFromCsv.pg ];
then
  echo "# Gnuplot configuration [gplot_generateFromCsv.pg] not found."
  exit 1;
fi

# Running gnuplot
cat gplot_generateFromCsv.pg |gnuplot 2>/dev/null
if [ -f data.png ]; then
  echo "# Grafic generated with success. See data.png"
else
    echo "#% ERROR generating graphics - file data.png not found."
fi


exit 0;
