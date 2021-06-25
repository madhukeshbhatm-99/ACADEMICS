echo -n "Enter the number upto which the sum of even numbers is needed to be computed: "
read n
i=2
sumEVN=0
while [ $i -lt $n ] 
do
	sumEVN=$(echo `expr $sumEVN + $i`)
	i=$(echo `expr $i + 2`)
done
echo The sum of even numbers from 0 to $n is $sumEVN
