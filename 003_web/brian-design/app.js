const menu = document.querySelector("#mobile-menu");
const menulinks = document.querySelector(".navbar-menu");

// display mobile menu
const mobileMenu = () =>{
  menu.classList.toggle('is-active');
  menulinks.classList.toggle('active');

}

menu.addEventListener('click', mobileMenu);

