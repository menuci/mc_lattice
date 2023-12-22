

set yrange[0:100]

plot "out.put" u 1:2 t "# A" w l lw 2 lc 7,\
 	 "out.put" u 1:3 t "# B" w l lw 2 lc 1

