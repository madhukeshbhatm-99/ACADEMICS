  echo -n "Enter any String: "
  read string
  vowCount=$(echo $string | grep -o -i "[aeiou]" | wc --lines)
  echo "Number of Vowels in the given string: $vowCount"


