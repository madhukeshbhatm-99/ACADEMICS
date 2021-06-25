echo -n "Enter the number of terms to be generated: "
read n
a=0
b=1
i=2
echo -n "Fibonacci series upto $n terms: $a $b "
while [ $i -le $n ]
do
	c=`expr $a + $b`
	echo -n "$c "
	a=$(echo $b)
	b=$(echo $c)
	i=`expr $i + 1`
done
echo ""
