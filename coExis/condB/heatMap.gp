set xrange[0:1]
set yrange[0:1]

unset key

set size ratio 1
set xlabel "gamma"
set ylabel "p0"

set tics out
set tics nomirror

set palette rgb 7,6,10

plot "survProb.dat" using 2:1:3 with image
