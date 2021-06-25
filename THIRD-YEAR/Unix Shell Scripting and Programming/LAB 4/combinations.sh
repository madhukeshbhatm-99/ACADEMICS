echo The possible combinations of 1 2 3 are:
c=1
for i in 1 2 3
do
	for j in 1 2 3
	do
		for k in 1 2 3
		do
			echo $c. $i $j $k
			c=$(echo `expr $c + 1`)
		done
	done
done

