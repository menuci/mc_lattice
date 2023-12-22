set terminal gif animate delay 1
set output "test.gif"

#set size 100, 100

unset xtics
unset ytics
unset key

set xrange[0:100]
set yrange[-2:2]

#plot "tempo3.dat" u 1:($3==1?$2:1./0.) lc 7 pointtype 5 ps 1

do for[i=0:100]{ plot sprintf("tempo%d.dat",i) u 1:($3==1?$2:1./0.) lc rgb 'red' pointtype 5 ps 0.8, sprintf("tempo%d.dat",i) u 1:($3==0?$2:1./0.) lc rgb 'green' pointtype 5 ps 0.8}
