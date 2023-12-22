#!/bin/bash
# Basic while loop
	./makefile
	for k in {1..99}
		do
			echo p0: $k
			for i in {1..99}
				do
					echo main: $i
					for j in {1..500}
						do	
							./main $i $k
						done
					rm q*
					awk -v gb=$i -v p0=$k -f media.awk rg* >> survProb.dat
					rm rg*
				done
		done
echo All done
