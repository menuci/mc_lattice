set term cairolatex pdf standalone blacktext header '\usepackage{amsmath}'
set output 'image.tex'

set xrange[0.01:0.99]
set yrange[0.01:0.99]

unset key

set size ratio 1

set title 'L = 1500'
set xlabel 'g_B'
set ylabel '$\rho_{A0}$'

set xtics .2
#set format x '\tiny$'
set ytics 0.2
set tics out
set tics nomirror

set cblabel '$\rho_{A}$'

set palette rgb 7,6,10
plot 'survProb.dat' using 2:1:3 with image
