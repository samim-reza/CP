var time = 0
let message
if(time<12){
    message = "Good morning"
}else{
    message = "Good afternoon"
}
let x= 100
let y = 100
let z = 100
document.getElementById('header').innerHTML = message
// window.changeColor = function(){
function changeColor(){
    let val = `rgb(${x},${y},${z})`
    console.log(val)
    document.getElementById('header').style.color = val
    x = x+10
    y = y+10
    z = z+10
    // if(x%2==0){
    // document.getElementById('header').style.color = "red"
    // x=x+100
    // }else{
    // document.getElementById('header').style.color = "green"
    // x=x+100
    // }
}
console.log(window);