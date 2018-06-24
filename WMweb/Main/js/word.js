let paras = window.location.href.split('?');
let id = "";
if(paras.length > 1) {
    paras = paras[1].split('&');
    id = paras[0];
    if(id.substr(-1)==="#")
        id = id.substr(0, id.length-1);
    if (id.split('=')[0] !== "id") id = "";

    if(document.getElementById("userid"))
        document.getElementById("userid").innerText = 'User:' + id.split('=')[1];

}

document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.datepicker');
    M.Datepicker.init(elems, {});
});
document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.carousel');
    M.Carousel.init(elems, {});
});

function gotoNote(){
    window.location.href='note.html?' + id;
}
function gotoUser(){
    window.location.href='account.html?' + id;
}
function logOut(){
    window.location.href='../Login/welcome.html';
}



