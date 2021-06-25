echo -n "Enter the base of the triangle: "
read b
echo -n "Enter the height of the triangle: "
read h
area=$(echo 0.5 \* $b \* $h | bc)
echo "The area of a triangle with hieght $h and base $b is : $area"
