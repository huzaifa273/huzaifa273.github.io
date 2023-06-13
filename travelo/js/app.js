
const parallax_el = document.querySelectorAll(".parallax")

let xValue = 0, yValue = 0;

window.addEventListener("mousemove", (e) => {
    xValue = e.clientX - window.innerWidth / 2;
    yValue = e.clientY - window.innerHeight / 2;

    parallax_el.forEach(el => {
        let speedx = el.dataset.speedx;
        let speedy = el.dataset.speedy;
        el.style.transform = `translateX(calc(-50% + ${-xValue * speedx}px)) translateY(calc(-50% + ${yValue * speedy}px))`
    });
})


const hamburgerBtn = document.getElementById('hamburger-btn');
const registration = document.getElementById('registration');

hamburgerBtn.addEventListener('click', () => {
    registration.classList.toggle('show')
});


// Eye tracker

$("body").mousemove(function(event) {
    var eye = $(".eye");
    var x = (eye.offset().left) + (eye.width() / 2);
    var y = (eye.offset().top) + (eye.height() / 2);
    var rad = Math.atan2(event.pageX - x, event.pageY - y);
    var rot = (rad * (180 / Math.PI) * -1) + 180;
    eye.css({
      '-webkit-transform': 'rotate(' + rot + 'deg)',
      '-moz-transform': 'rotate(' + rot + 'deg)',
      '-ms-transform': 'rotate(' + rot + 'deg)',
      'transform': 'rotate(' + rot + 'deg)'
    });
});


// Changing the color of the orbit text 
const color = document.getElementById('color');
window.onscroll = function () { 
    if (document.body.scrollTop >= 800 || document.documentElement.scrollTop >= 800 ) {
        color.classList.remove("color");
        color.classList.add("dark-color");
    } 
    else {
        color.classList.remove("dark-color");
        color.classList.add("color");
    }
};