echo -n "Enter the basic salary in Rs. : "
read basic
if [ $basic -ge 1000 ]
then
	da=$(echo 0.10 \* $basic | bc) 
	hra=$(echo 0.20 \* $basic | bc)
	gross=$(echo $basic + $da + $hra | bc)
	echo DA: $da Rs.
	echo HRA: $hra Rs.
	echo The gross salary is $gross Rs.
else
	echo The basic salary must be atleast 1000 Rs.
fi
