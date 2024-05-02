let number = 0

function countNumber(){
    let x = Math.random()*255
    let y = Math.random()*255
    let z = Math.random()*255
    let val = `rgb(${x},${y},${z})`
    number = number + 1
    document.getElementById('header').innerHTML = number
    document.getElementById('c').style.backgroundColor = val

}
function reset(){
    let val = `rgb(255,255,255)`
    number = 0
    document.getElementById('header').innerHTML = number
    document.getElementById('c').style.backgroundColor = val
}
console.log(window);