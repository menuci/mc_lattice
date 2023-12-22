set xrange[0.02:0.98]
set yrange[0.02:0.98]

unset key

set size ratio 1
set xlabel "gB"
set ylabel "p0"

set tics out
set tics nomirror

set palette rgb 7,6,10
set title "L = 1000"
plot "survProb1000.dat" using 2:1:3 with image
