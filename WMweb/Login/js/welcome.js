


function login(){
    $.ajax({
        data: "login_req&wmadmin&wmadmin",
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = '../Main/user.html?id=wmadmin';
        }
    });
}
function signup(){
    $.ajax({
        data: "signup",
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = 'sign.html';
        }
    });
}
function tourvisit(){
    $.ajax({
        data: "tour",
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = 'search.html';
        }
    });
}