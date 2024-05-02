count_characters() {
    local string=$1
    local length=${#string}
    local alphabet_count=0
    local digit_count=0
    local special_count=0

    for (( i=0; i<$length; i++ )); do
        char="${string:$i:1}"
        if [[ $char =~ [[:alpha:]] ]]; then
            (( alphabet_count++ ))
        elif [[ $char =~ [[:digit:]] ]]; then
            (( digit_count++ ))
        else
            (( special_count++ ))
        fi
    done

    echo "Alphabets = $alphabet_count"
    echo "Digits = $digit_count"
    echo "Special characters = $special_count"
}

echo "Enter a string:"
read input_string

count_characters "$input_string"

