const desc = document.getElementById("desc");
const alignRight = document.getElementById("input1");
const firstContainer = document.getElementById("firstContainer");
const zero = document.getElementById("vini");
const one = document.getElementById("raphinha");
const two = document.getElementById("neymar");

const alignLeft = document.getElementById("input2");
const secondContainer = document.getElementById("secondContainer");
const alignCenter = document.getElementById("input3");
const thirdContainer = document.getElementById("thirdContainer");
const button = document.getElementById("socrates");
let firstTrue = 0,
  secondTrue = 0,
  thirdTrue = 0,
  clickedOnce = 0;

const p1 = document.getElementById("zico");
const p2 = document.getElementById("junior");
const p3 = document.getElementById("falcao");
const answer = document.getElementById("toninho");

function handleSolved() {
  desc.parentNode.removeChild(desc);
  button.style.display = "inline-block";
  button.addEventListener("click", () => {
    if (!clickedOnce) {
      clickedOnce = 1;
      zico.style.color = "#fff";
      junior.style.color = "#fff";
      falcao.style.color = "#fff";
      zero.style.border = "unset";
      one.style.borderTop = "unset";
      one.style.borderLeft = "unset";
      two.style.borderTop = "unset";

      setTimeout(() => {
        zico.style.color = "#1a1a1a";
        zico.style.fontSize = "5vh";
        junior.style.color = "#1a1a1a";
        junior.style.fontSize = "5vh";
        falcao.style.color = "#1a1a1a";
        falcao.style.fontSize = "5vh";
        answer.style.display = "inline-block";
      }, 1000);
    } else {
      if (toninho.value === "021") {
        window.location.href = "//onboarding.titi-lima.repl.co/cf";
      }
    }
  });
}

alignRight.addEventListener("input", (e) => {
  firstContainer.style.justifyContent = e.target.value;
  firstTrue =
    firstContainer.style.justifyContent === "right" ||
    firstContainer.style.justifyContent === "flex-end" ||
    firstContainer.style.justifyContent === "end";
  console.log(firstTrue, secondTrue, thirdTrue);
  if (firstTrue && secondTrue && thirdTrue) handleSolved();
});
alignLeft.addEventListener("input", (e) => {
  secondContainer.style.justifyContent = e.target.value;
  secondTrue =
    secondContainer.style.justifyContent === "left" ||
    secondContainer.style.justifyContent === "flex-start" ||
    secondContainer.style.justifyContent === "start";
  console.log(firstTrue, secondTrue, thirdTrue);
  if (firstTrue && secondTrue && thirdTrue) handleSolved();
});

alignCenter.addEventListener("input", (e) => {
  thirdContainer.style.justifyContent = e.target.value;
  thirdTrue =
    thirdContainer.style.justifyContent === "center" ||
    thirdContainer.style.justifyContent === "space-around" ||
    thirdContainer.style.justifyContent === "space-evenly";
  if (firstTrue && secondTrue && thirdTrue) handleSolved();
});
