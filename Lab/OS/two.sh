factorial() {
    local num=$1
    local result=1

    for ((i = 2; i <= num; i++)); do
        result=$((result * i))
    done

    echo $result
}

calculate_sum() {
    local num1=$1
    local num2=$2
    local sum=$((num1 + num2))

    echo $sum
}

echo "Enter first number:"
read num1
echo "Enter second number:"
read num2

factorial_num1=$(factorial $num1)
factorial_num2=$(factorial $num2)

sum=$(calculate_sum $num1 $num2)

echo "Factorial of $num1: $factorial_num1"
echo "Factorial of $num2: $factorial_num2"
echo "Sum of $num1 and $num2: $sum"

