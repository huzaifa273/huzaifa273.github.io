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
    // if(registration.classList.contains('show')){
    //     window.addEventListener('click', () => {
    //         if(registration.classList.contains('show')){
    //             registration.classList.remove('show')
    //             console.log("hello");
    //         }else{
    //         };
    //     })
    // };
});
