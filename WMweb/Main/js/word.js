document.addEventListener('DOMContentLoaded', function() {
    var elems = document.querySelectorAll('.datepicker');
    var instances = M.Datepicker.init(elems, {});
});
document.addEventListener('DOMContentLoaded', function() {
    var elems = document.querySelectorAll('.carousel');
    var instances = M.Carousel.init(elems, {});
});

function gotoUser(){
    window.location.href='account.html';
}
function logOut(){
    window.location.href='../Login/welcome.html'
}

function jsReadFiles() {
    var fso = new ActiveXObject("Scripting.FileSystemObject");

    var f1 = fso.createtextfile("test.txt",true);

    alert("File last modified: " + f1.DateLastModified);
}
jsReadFiles();