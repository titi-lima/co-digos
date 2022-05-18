let color = document.getElementById("color");
let body = document.querySelector("body");
let rectangle = document.getElementById("rectangle");

const button = document.getElementById("button");

button.addEventListener("click", myFunction);

function myFunction() {
  switch (color.innerText) {
    case "#292929":
      color.innerText = "#F2F2F2";
      body.style.backgroundColor = "#F2F2F2";
      rectangle.style.backgroundColor = "#C7C7C7";
      break;
    case "#F2F2F2":
      color.innerText = "#C7C7C7";
      body.style.backgroundColor = "#C7C7C7";
      rectangle.style.backgroundColor = "#F2F2F2";
      break;
    case "#C7C7C7":
      color.innerText = "#292929";
      body.style.backgroundColor = "#292929";
      rectangle.style.backgroundColor = "#F2F2F2";
      break;
  }
}
