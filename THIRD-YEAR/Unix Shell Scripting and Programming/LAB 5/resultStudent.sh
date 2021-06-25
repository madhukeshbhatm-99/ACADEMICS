echo Enter the marks of three subjects: 
echo -n "Subject 1: "
read m1
echo -n "Subject 2: "
read m2
echo -n "Subject 3: "
read m3
echo -------------------
avg3=0
if [ $m1 -le 50 -o $m2 -le 50 -o $m3 -le 50 ]
then
	echo Average: $avg3
	echo Result: FAIL
else
	sum3=`expr $m1 + $m2 + $m3`
	avg3=`expr $sum3 / 3`
	echo Average: $avg3
	if [ $avg3 -ge 90 ]
	then 
		echo Result: DISTINCTION
	elif [ $avg3 -ge 60 ]
	then
		echo Result: FIRST CLASS
	else
		echo Result: SECOND CLASS
	fi
fi
