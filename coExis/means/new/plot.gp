set term cairolatex pdf standalone blacktext header '\usepackage{amsmath}'
set output 'image.tex'

#set xrange[100:0000]
set yrange[0:1]

set xlabel '$t$'
set ylabel '$\rho__{A}$'

unset key

set logscale

set title '$\gamma = 1$'

plot 'average1.dat' t '$ \rho_0 = 0.1 $' w l lw 4 ,\
	 'average2.dat' t '$ \rho_0 = 0.2 $' w l lw 4 ,\
	 'average3.dat' t '$ \rho_0 = 0.3 $' w l lw 4 ,\
	 'average4.dat' t '$ \rho_0 = 0.4 $' w l lw 4 ,\
	 'average5.dat' t '$ \rho_0 = 0.5 $' w l lw 4 ,\
	 'average6.dat' t '$ \rho_0 = 0.6 $' w l lw 4 ,\
	 'average7.dat' t '$ \rho_0 = 0.7 $' w l lw 4 ,\
	 'average8.dat' t '$ \rho_0 = 0.8 $' w l lw 4 ,\
	 'average9.dat' t '$ \rho_0 = 0.9 $' w l lw 4