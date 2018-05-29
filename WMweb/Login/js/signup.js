function signup(){
    let id = document.getElementById('signid').value;
    let password = document.getElementById('signpassword').value;
    let confirm = document.getElementById('signconfirm').value;
    if(password!==confirm)return;
    $.ajax({
        data: "sign_req&" + id + "&" + password,
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = 'welcome.html?' + id + "&" + password;
        }
        else if(res === "redef"){
            alert("This user id has been registered. Try another one.");
        }
    });
}