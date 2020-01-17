set terminal png
set output 'graph.png'
set datafile seperator ","
set xtics rotate by -45
plot "../data/aq.csv" using 6:xticlabels(2) with boxes
