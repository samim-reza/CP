read -p "Enter a number: " number

largest=-1
second_largest=-1

while [ $number -gt 0 ]
do
    digit=$((number % 10))

    if [ $digit -gt $largest ]
    then
        second_largest=$largest
        largest=$digit
    elif [ $digit -gt $second_largest ] && [ $digit -ne $largest ]
    then
        second_largest=$digit
    fi

    number=$((number / 10))
done

if [ $second_largest -eq -1 ]
then
    echo "There is no second largest digit."
else
    echo "The second largest digit is: $second_largest"
fi

