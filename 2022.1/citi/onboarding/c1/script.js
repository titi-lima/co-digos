const alignRight = document.getElementById("input1");
const firstContainer = document.getElementById("firstContainer");
const alignLeft = document.getElementById("input2");
const secondContainer = document.getElementById("secondContainer");
const alignCenter = document.getElementById("input3");
const thirdContainer = document.getElementById("thirdContainer");
let firstTrue = 0,
  secondTrue = 0,
  thirdTrue = 0;

function handleSolved() {
  console.log("ebaa");
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
  thirdTrue = thirdContainer.style.justifyContent === "center";
  console.log(firstTrue, secondTrue, thirdTrue);
  if (firstTrue && secondTrue && thirdTrue) handleSolved();
});
