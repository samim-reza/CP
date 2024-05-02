read -p "Give a number: " a
num1=0
num2=1

echo "Fibonacci sequence up to $a:"

while [ $num1 -le $a ]
do
  echo -n "$num1 "
  temp=$((num1 + num2))
  num1=$num2
  num2=$temp
done

echo ""

