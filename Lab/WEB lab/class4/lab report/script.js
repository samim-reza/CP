function checkPalindrome() {
    let input = document.getElementById("input").value;
    console.log(input);
    if (input === "") {
        document.getElementById('output').innerHTML = "Please enter something";
        return;
    }
    let check = input.split('').reverse().join('');
    console.log(check);
    if (input == check) {
        document.getElementById('output').innerHTML = "Palindrome";
        return;
    }
    else {
        document.getElementById('output').innerHTML = "Not palindrome";
        return;
    }
}