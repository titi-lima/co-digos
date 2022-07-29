const bg = document.getElementById("bg");
const b1 = document.getElementById("b1");
const body = document.querySelector("body");
const h1 = document.querySelector("h1");
const nicetry = document.getElementById("nicetry");
const t = document.getElementById("t");
const y = document.getElementById("y");
const hide = document.getElementsByClassName("hide");
const mark = document.getElementById("mark");
const tiago = document.getElementById("first");
const matheus = document.getElementById("second");

b2 = document.getElementById("b2");

b1.addEventListener("click", () => {
  if (bg.value === "0e2a1b") {
    body.style.backgroundColor = "#0e2a1b";
    nicetry.style.visibility = "visible";
    bg.parentNode.removeChild(bg);
    body.removeChild(b1);
  }
});

b2.addEventListener("click", () => {
  if (tiago.innerText === "tiago" && matheus.innerText === "matheus") {
    // mark.style.left = "-2vw";
    t.innerText = "e";
    t.classList.remove("hide");
    y.innerText = "agradecem a sua presença!";
    y.classList.remove("hide");
    b2.classList.add("hide");
    setTimeout(() => {
      window.location.href = "https://youtu.be/NJIzaL3yMrQ?t=100";
    }, 5000);
  }
});
