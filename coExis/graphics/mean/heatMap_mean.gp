set term cairolatex pdf standalone blacktext header '\usepackage{amsmath}'
set output 'mean.tex'

set xrange[0:1]
set yrange[0:1]

unset key

set size ratio 1
set xlabel '$\gamma'
set ylabel '$\rho__{A_0}$'

set tics out
set tics nomirror
set title '100 samples'
set palette rgb 7,6,10

set cblabel '\rho__{A}'

plot "mean.dat" using 2:1:3 with image
