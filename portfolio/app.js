var navToggle = document.querySelector(".nav-toggle");
var links = document.querySelector(".links");

navToggle.addEventListener("click", function() {
    links.classList.toggle("show-links");
});

links.addEventListener("click", function() {
    links.classList.remove("show-links");
});

