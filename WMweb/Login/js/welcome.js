
if(window.location.href.split('?').length > 1){
    let pre=window.location.href.split('?')[1].split('&');
    document.getElementById("inputid").value = pre[0];
    document.getElementById("inputpassword").value = pre[1];
}

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

function login(){
    $.ajax({
        data: "login_req&" + document.getElementById("inputid").value+"&" + document.getElementById("inputpassword").value,
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = '../Main/user.html?' + compile("id=" + document.getElementById("inputid").value);
        }
    });
}
function signup(){
    window.location.href = 'sign.html';
}