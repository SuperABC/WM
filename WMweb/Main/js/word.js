let paras = window.location.href.split('?');
let id = "";
if(paras.length > 1) {
    paras = paras[1].split('&');
    id = paras[0];
    if (id.split('=')[0] !== "id") id = "";

    if(document.getElementById("userid"))
        document.getElementById("userid").innerText = 'User:' + window.location.href.split('?')[1].split('=')[1];

    if(paras.length>1){
        if(paras[1].split('=')[0] === "word"){
            $.ajax({
                data: "word_search&" + paras[1].split('=')[1],
                url: 'http://127.0.0.1:4497',
                dataType: "jsonp",
                jsonp: "callback",
                jsonpCallback: "success_jsonpCallback"
            }).done(function (res) {
                let tmp = JSON.parse(res);
                document.getElementById("title").innerText=tmp.word;
                document.getElementById("trans").innerText=tmp.trans;
                document.getElementById("examp").innerText=tmp.examp;
            });
        }
    }
}

document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.datepicker');
    M.Datepicker.init(elems, {});
});
document.addEventListener('DOMContentLoaded', function() {
    let elems = document.querySelectorAll('.carousel');
    M.Carousel.init(elems, {});
});

function gotoUser(){
    window.location.href='account.html?' + id;
}
function logOut(){
    window.location.href='../Login/welcome.html';
}

function queryWord(){
    alert(document.getElementById("input").value);
    $.ajax({
        data: "word_search&" + document.getElementById("input").value,
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(JSON.parse(res).length) alert(res);
        else alert(JSON.parse(res).word);
    });
}


