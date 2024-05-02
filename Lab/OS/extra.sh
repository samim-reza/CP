echo "Enter any number: "
read num

n=$num
rev=0

while [ $num -gt 0 ]
do
  rem=$(( $num % 10 ))
  rev=$(( $rev * 10 + $rem ))
  num=$(( $num / 10 ))
done

echo "Reverse of $n is $rev"

if [ $n -eq $rev ]
then
  echo "$n is a palindrome number."
else
  echo "$n is not a palindrome number."
fi
