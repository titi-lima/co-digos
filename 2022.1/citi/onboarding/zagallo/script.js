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

bg.addEventListener("input", () => {
  if (
    bg.value.length &&
    bg.value.length % 2 &&
    !(
      "0" <= bg.value[bg.value.length - 1] &&
      bg.value[bg.value.length - 1] <= "9"
    )
  ) {
    bg.value = bg.value.slice(0, -1);
  } else if (
    bg.value.length &&
    !(bg.value.length % 2) &&
    !(
      "a" <= bg.value[bg.value.length - 1].toLowerCase() &&
      bg.value[bg.value.length - 1].toLowerCase() <= "f"
    )
  ) {
    bg.value = bg.value.slice(0, -1);
  }
});

b1.addEventListener("click", () => {
  body.style.backgroundColor = "#" + bg.value.toLowerCase();
  if (bg.value.toLowerCase() === "0e2b1a") {
    nicetry.style.visibility = "visible";
    bg.parentNode.removeChild(bg);
    body.removeChild(b1);
  }
});

b2.addEventListener("click", () => {
  if (
    tiago.innerText.toLowerCase().includes("tiago") &&
    matheus.innerText.toLowerCase().includes("matheus")
  ) {
    // mark.style.left = "-2vw";
    t.innerText = "e";
    t.classList.remove("hide");
    y.innerText = "agradecem a sua presença!";
    y.classList.remove("hide");
    b2.classList.add("hide");
    setTimeout(() => {
      window.location.href = "https://www.youtube.com/watch?v=-0hmmX96QvY";
    }, 5000);
  }
});
