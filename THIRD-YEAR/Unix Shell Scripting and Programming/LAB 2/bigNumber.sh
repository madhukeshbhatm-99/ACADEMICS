echo Enter three numbers: 
read a
read b
read c
if [ $a -gt $b ]
then
	if [ $a -gt $c ]
	then
		echo $a is the largest of all three numbers
	else
		echo $c is the largest of all three numbers
	fi
elif [ $b -gt $c ]
then
	echo $b is the largest of all three numbers
else
	echo $c is the largest of all three numbers  
fi
