const next = document.getElementById("next");
const prev = document.getElementById("prev");
const nome = document.getElementById("name");
const nomeAux = document.getElementById("nameAux");
const ourTattooist = document.getElementById("ourTattooist");
const ourTattooistAux = document.getElementById("ourTattooistAux");

next.addEventListener("click", () => {
  switch (nome.innerText) {
    case "Samuel Reis":
      ourTattooistAux.src = "assets/mylena.png";
      nomeAux.innerText = "Mylena Soares";
      ourTattooist.classList.add("hidden");
      ourTattooistAux.classList.remove("hidden");
      nomeAux.classList.remove("hidden");
      nome.classList.add("hidden");
      nome.innerText = nomeAux.innerText;
      prev.classList.remove("inactive");
      prev.classList.add("active");
      break;
    case "Mylena Soares":
      ourTattooist.src = "assets/pedro.png";
      nome.innerText = "Pedro Basílio";
      ourTattooistAux.classList.add("hidden");
      ourTattooist.classList.remove("hidden");
      next.classList.add("inactive");
      next.classList.remove("active");
      nome.classList.remove("hidden");
      nomeAux.classList.add("hidden");
      break;
    case "Pedro Basílio":
      break;
  }
});
prev.addEventListener("click", () => {
  switch (nome.innerText) {
    case "Samuel Reis":
      break;
    case "Mylena Soares":
      nome.innerText = "Samuel Reis";
      ourTattooist.src = "assets/samuel.png";
      ourTattooistAux.classList.add("hidden");
      ourTattooist.classList.remove("hidden");
      nome.classList.remove("hidden");
      nomeAux.classList.add("hidden");
      prev.classList.add("inactive");
      prev.classList.remove("active");
      break;
    case "Pedro Basílio":
      ourTattooistAux.src = "assets/mylena.png";
      nomeAux.innerText = "Mylena Soares";
      ourTattooist.classList.add("hidden");
      ourTattooistAux.classList.remove("hidden");
      nomeAux.classList.remove("hidden");
      nome.classList.add("hidden");
      nome.innerText = nomeAux.innerText;
      next.classList.remove("inactive");
      next.classList.add("active");
      break;
  }
});
