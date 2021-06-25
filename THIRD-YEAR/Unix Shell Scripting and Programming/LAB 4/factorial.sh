fact=1
echo -n "Enter any number from 1 to 20: "
read num
n=$(echo $num) 
while [ $n -gt 0 ]
do
	fact=$(echo `expr $fact \* $n`)
	n=$(echo `expr $n - 1`)
done
echo The factorial of $num "($num!)" is $fact
