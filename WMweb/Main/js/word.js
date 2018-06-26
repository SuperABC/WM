if(window.location.href.substr(-1)==="#")
    window.location.href = window.location.href.substr(0, window.location.href.length-1);
let paras = window.location.href.split('?');
let id = "";
if(paras.length > 1) {
    paras = paras[1].split('&');
    id = paras[0];
    id = uncompile(id);

    if(id.split('=')[1] === undefined)
        logOut();
    if(document.getElementById("userid"))
        document.getElementById("userid").innerText = 'User:' + id.split('=')[1];

    for(let i = 1; i < paras.length; i++){
        paras[i] = uncompile(paras[i]);
    }

}

document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.datepicker');
    M.Datepicker.init(elems, {format:'yyyy/mm/dd'});
});
document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.carousel');
    M.Carousel.init(elems, {});
});

function compile(code)
{
    let c=String.fromCharCode(code.charCodeAt(0)+code.length);
    for(let i=1;i<code.length;i++){
        c+=String.fromCharCode(code.charCodeAt(i)+code.charCodeAt(i-1));
    }
    return escape(c);
}
function uncompile(code)
{
    code=unescape(code);
    let c=String.fromCharCode(code.charCodeAt(0)-code.length);
    for(let i=1;i<code.length;i++){
        c+=String.fromCharCode(code.charCodeAt(i)-c.charCodeAt(i-1));
    }
    return c;
}

function gotoNote(){
    window.location.href='note.html?' + compile(id);
}
function logOut(){
    window.location.href='../Login/welcome.html';
}



