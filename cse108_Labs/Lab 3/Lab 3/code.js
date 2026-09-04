
function display(val){
    
    document.getElementById("rez").value +=val
}

function solve(){
    let x = document.getElementById("rez").value
    let y = eval(x)
    document.getElementById("rez").value = y
}

function clr(){
    document.getElementById("rez").value = ""
}