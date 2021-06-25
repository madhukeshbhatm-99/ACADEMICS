echo -n "Enter first number: "
read a
echo -n "Enter second number: "
read b
echo "Enter the operation to be performed: \n 1. Addition \n 2. Substraction \n 3. Multiplication \n 4. Division \n 5. Modulus"
echo -n "Enter your option: "
read op
case $op in
	1) echo -n "Addition of $a and $b is "
	   echo $a + $b | bc;;
	2) echo -n "Subtraction of $a and $b is " 
	   echo $a - $b | bc;;
	3) echo -n "Multiplication of $a and $b is "
	   echo $a \* $b | bc;;
	4) if [ $a -eq 0 -o $b -eq 0 ]
	   then
	   	echo Exception: One of the operand or both the operands are 0
	   	exit 0
	   fi
	   echo -n "Division of $a and $b is "
	   echo "scale = 3;" $a / $b | bc -l;;
	5) echo -n "Modulus of $a and $b is "
	   echo  $a % $b | bc ;;
	*) echo "Invalid operation"
esac
