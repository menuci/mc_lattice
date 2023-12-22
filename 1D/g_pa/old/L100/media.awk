# na linha de comando: awk -v gb='gb' -v p0='p0' -f media.awk input > output
{	
	data += $0
	cont++
}
END{
	printf "%.2f %.2f %0.5f\n", p0*0.02, gb*0.02, data/cont
}
