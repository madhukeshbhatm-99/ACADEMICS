echo -n "Enter a number upto which the sum is needed to be computed: "
read n
num=$(echo `expr $n + 1`)
mult=$(echo `expr $n \* $num`)
res=$(echo `expr $mult / 2`)
echo The sum from 1 to $n is $res
