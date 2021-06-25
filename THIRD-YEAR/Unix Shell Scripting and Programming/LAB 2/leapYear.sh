echo -n "Enter a year (YYYY): "
read y
if [ `expr $y % 4` -eq 0 -a `expr $y % 100` -ne 0 -o `expr $y % 400` -eq 0 ]
then
	echo Yes, $y is a leap year
else
	echo No, $y is not a leap year
fi
