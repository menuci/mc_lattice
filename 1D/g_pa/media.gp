set yrange[0:1.1]
set xrange[0:1]

set xlabel "Gb"
set ylabel "rho_A"

plot "media_p01.dat" t "0.1" w lp lc 7 pt 7,\
 	 "media_p02.dat" t "0.2" w lp lc 6 pt 5,\
	 "media_p03.dat" t "0.3" w lp lc 9 pt 4,\
	 "media_p04.dat" u 2:3 t "0.4" w lp lc 8 pt 6,\
	 "media_p05.dat" u 2:3 t "0.5" w lp lc 4 pt 3
