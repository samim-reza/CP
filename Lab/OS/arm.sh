read -p "Give a number: " a
num1=$a
c=$a
num2=0
count=0

while [ $c -ne 0 ]
do
    c=$((c / 10))
    count=$((count + 1))
done

while [ $a -ne 0 ]
do
    digit=$((a % 10))
    temp=$digit
    i=1
    while [ $i -lt $count ]
    do
        temp=$((temp * digit))
        i=$((i + 1))
    done
    num2=$((num2 + temp))
    a=$((a / 10))
done
if [ $num1 -eq $num2 ]
then
    echo "Armstrong"
else
    echo "Not Armstrong"
fi

