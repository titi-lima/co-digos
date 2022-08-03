const input = document.getElementById("matheusCunha");

const E = document.getElementById("richarlison");
const b = document.getElementById("rodrygo");
const a = document.getElementById("martinelli");

const img1 = document.getElementById("casemiro");
const img2 = document.getElementById("marquinhos");

function handleSolved() {
  window.location.href = "../zagallo";
}

rivaldo.addEventListener("click", () => {
  switch (input.placeholder) {
    case "id":
      if (input.value === "34035456") {
        input.value = "";
        input.placeholder = "Foto de perfil";
        b.style.transform = "rotate(45deg)";
      }
      break;
    case "Foto de perfil":
      if (
        input.value === "https://avatars.githubusercontent.com/u/34035456?v=4"
      ) {
        input.placeholder = "???";
        input.value = "";
        input.maxLength = "3";
        img2.src = "https://avatars.githubusercontent.com/u/34035456?v=4";
        img1.src = "https://avatars.githubusercontent.com/u/34035456?v=4";
        E.style.borderTop = "unset";
        E.style.borderLeft = "unset";
        b.style.borderTop = "unset";
        b.style.borderLeft = "unset";
        a.style.borderTop = "unset";
        a.style.borderRight = "unset";
      }
      break;

    default:
      if (input.value.toLowerCase() === "eba") {
        handleSolved();
      }
      break;
  }
});
