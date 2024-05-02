read -p "Give a number: " a
num1=$a
num2=0

while [ $a -ne 0 ]
do
    temp=$((a % 10))
    num2=$((num2 * 10 + temp))
    a=$((a / 10))
done

if [ $num1 -eq $num2 ]
then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi

