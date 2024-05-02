highest=0
second_highest=0
third_highest=0

echo "Enter numbers (separated by spaces):"
read -a numbers


for num in "${numbers[@]}"; do
    if (( num > highest )); then
        third_highest=$second_highest
        second_highest=$highest
        highest=$num
    elif (( num > second_highest && num < highest )); then
        third_highest=$second_highest
        second_highest=$num
    elif (( num > third_highest && num < second_highest )); then
        third_highest=$num
    fi
done

sum=$((second_highest + third_highest))

echo "Second highest number: $second_highest"
echo "Third highest number: $third_highest"
echo "Sum of second highest and third highest: $sum"

