#!/bin/bash
# Basic while loop
	./makefile
	for i in {1..9}
		do
			echo p0: $i
			for j in {1..500}
				do	
					./main $i
				done
			awk -f average.awk q* > average$i.dat
			rm q*
		done
echo All done
