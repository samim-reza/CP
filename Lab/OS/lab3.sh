read -p "Enter Number: " a
sum=0
sum1=0

for ((i=0; i<=a; i++))
do
  if [ $((i % 2)) -eq 1 ]; then
    sum=$((sum + i))
  fi
  if [ $((i % 2)) -eq 0 ]; then
    sum1=$((sum1 + i))
  fi
done

echo "Sum of odd numbers up to $a: $sum"
echo "Sum of even numbers up to $a: $sum1"

