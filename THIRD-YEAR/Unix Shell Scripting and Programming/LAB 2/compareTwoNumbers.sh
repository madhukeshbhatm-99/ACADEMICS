echo -n "Enter first number: "
read a
echo -n "Enter second number: "
read b
if [ $a -eq $b ]
then
	echo $a and $b are equal
elif [ $a -gt $b ]
then
	echo $a is greater than $b
else 
	echo $a is lesser than $b
fi
