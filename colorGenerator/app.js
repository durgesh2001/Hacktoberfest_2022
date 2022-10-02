const simple = document.getElementById("simple");
const hex_value = document.getElementById("hex");
const button = document.getElementById("btn");
const color = document.querySelector(".color");

const marker = document.querySelector("#marker");
const item = document.querySelectorAll("a");



colors = ["Red", "Green", "Blue"];
hex = [1, 2, 3, 4, 5, 6, 7, 8, 9, "a", "b", "c", "d", "e", "f"];

//Menu slider

document.addEventListener("DOMContentLoaded", ()=>{
    marker.style.left = item[0].offsetLeft + "px"; 
    marker.style.width = item[0].offsetWidth + "px";
   })
 window.addEventListener("resize", indicator2)


function indicator2(){
    item.forEach(link => {
        if(link.classList.contains("active")){
            marker.style.left = link.offsetLeft + "px";
            marker.style.width = link.offsetWidth + "px";
        }
    })
}
function indicator(e){
    e.target.classList.add("active");
    marker.style.left = e.target.offsetLeft + "px";
    marker.style.width = e.target.offsetWidth + "px";
}

item.forEach((link) => {
    link.addEventListener("click", (e) =>{
        item.forEach(link => {
            if(link.classList.contains("active")){
                link.classList.remove("active")
            }
        })
          indicator(e);   
    })
})




//For simple colors
function click(){
button.addEventListener("click", ()=>{
    let randomNumber = Math.floor(Math.random() * colors.length);
    document.body.style.backgroundColor = colors[randomNumber];

    
    color.textContent = colors[randomNumber]

})
}
click();

//For Hex Colors
hex_value.addEventListener("click", ()=>{
    document.body.style.background = "white";
    color.textContent = "#ffffff";

    clickEvent();
    
});

function clickEvent(){
button.addEventListener("click", ()=>{
    let values = "#";
    for(i= 0; i<6; i++){
    let randomNumber = Math.floor(Math.random()* hex.length);
    values += hex[randomNumber]
    }
    color.textContent = values;
    document.body.style.backgroundColor = values;
})
};

simple.addEventListener("click", ()=>{
    document.body.style.backgroundColor = "#ffffff";
    color.textContent = "White"
    click();
})
