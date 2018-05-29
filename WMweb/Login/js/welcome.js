
if(window.location.href.split('?').length > 1){
    let pre=window.location.href.split('?')[1].split('&');
    document.getElementById("inputid").value = pre[0];
    document.getElementById("inputpassword").value = pre[1];
}


function login(){
    $.ajax({
        data: "login_req&" + document.getElementById("inputid").value+"&" + document.getElementById("inputpassword").value,
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = '../Main/user.html?id=' + document.getElementById("inputid").value;
        }
    });
}
function signup(){
    $.ajax({
        data: "sign_req",
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
        data: "tour_req",
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