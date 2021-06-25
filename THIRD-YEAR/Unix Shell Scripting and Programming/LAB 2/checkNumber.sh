echo -n 'Enter a number: ' 
read a
if [ $a -lt 0 ]
then
	echo The number $a is negative
elif [ $a -gt 0 ]
then
	echo The number $a is positive
else
	echo The nunber $a is zero
fi
