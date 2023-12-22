set term cairolatex pdf standalone blacktext header '\usepackage{amsmath}'
set output 'image.tex'

set xrange[0:1]
set yrange[0:1]

unset key

set size ratio 1
set xlabel '$\gamma'
set ylabel '$\rho__{A_0}$'

set tics out
set tics nomirror
set title "1 sample"
set palette rgb 7,6,10

set cblabel '\rho__{A}'

plot "1amostra.dat" using 2:1:3 with image
