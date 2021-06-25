echo -n "Enter the temperature in Fahrenheit: "
read fr
c=$(echo $fr -32 | bc)
co=$(echo "scale=2;" 5 / 9 | bc) 
cl=$(echo "scale=2;" $co \* $c | bc) 
echo The temperature in Celsius is $cl
