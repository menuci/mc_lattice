#!/bin/bash
# Basic while loop
	./makefile
	for j in {1..1000}
		do	
			echo $j
			./main 0.9 0.5
		done
	rm q*
echo All done
