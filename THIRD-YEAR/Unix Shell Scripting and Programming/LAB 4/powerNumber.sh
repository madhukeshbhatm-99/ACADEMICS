echo -n "Enter any number: "
read number
echo -n "Enter the power of $number to be computed: "
read pow
power=1
num=$(echo $number)
echo -n "The $pow power of $number ($number ^ $pow) is "
if [ $number -eq 1 -o $pow -eq 1 ]
then
	echo $num
else
	while [ $power -lt $pow ]
	do
		num=$(echo `expr $num \* $number`)
		power=$(echo `expr $power + 1`)
	done
	echo $num
fi
