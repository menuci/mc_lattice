set terminal gif animate delay 1
set output "test.gif"
	
unset xtics
unset xtics
unset ytics
unset key
unset colorbox
set size square


set xrange[-1:50]
set yrange[-1:50]

do for[i=0:600]{ plot sprintf("tempo%d.dat",i) u 1:($3==1?$2:1./0.) lc rgb 'red' pt 5 ps 1.2, sprintf("tempo%d.dat",i) u 1:($3==0?$2:1./0.) lc rgb 'green' pt 5 ps 1.2}
