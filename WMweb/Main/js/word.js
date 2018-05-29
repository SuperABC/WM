document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.datepicker');
    M.Datepicker.init(elems, {});
});
document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.carousel');
    M.Carousel.init(elems, {});
});

function gotoUser(){
    window.location.href='account.html';
}
function logOut(){
    window.location.href='../Login/welcome.html'
}
