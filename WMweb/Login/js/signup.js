function signup(){
    let id = document.getElementById('signid').value;
    let password = document.getElementById('signpassword').value;
    let confirm = document.getElementById('signconfirm').value;
    let email = document.getElementById('signemail').value;

    if(email.indexOf('@')===-1 || email.indexOf('@')!==email.lastIndexOf('@') || email.split('@')[1].indexOf('.')===-1){
        alert("email格式错误。");
        return;
    }

    if(password!==confirm){
        alert("两次输入的密码不一致。");
        return;
    }
    if(password.length < 6){
        alert("密码长度小于6位，安全性不足。");
        return;
    }
    switch(checkStrong(password)){
        case 1:
            alert("密码强度：弱");
            break;
        case 2:
            alert("密码强度：中");
            break;
        case 3:
        case 4:
            alert("密码强度：强");
            break;
    }


    $.ajax({
        data: "sign_req&" + id + "&" + password + "&" + email,
        url: 'http://127.0.0.1:4497',
        dataType: "jsonp",
        jsonp: "callback",
        jsonpCallback: "success_jsonpCallback"
    }).done(function (res) {
        if(res === "success") {
            window.location.href = 'welcome.html?' + compile(id) + "&" + compile(password);
        }
        else if(res === "redef"){
            alert("This user id has been registered. Try another one.");
        }
    });
}

function CharMode(iN){
    if (iN>=48 && iN <=57) //数字
        return 1;
    if (iN>=65 && iN <=90) //大写字母
        return 2;
    if (iN>=97 && iN <=122) //小写
        return 4;
    else
        return 8; //特殊字符
}
function bitTotal(num){
    modes=0;
    for (i=0;i<4;i++){
        if (num & 1) modes++;
        num /= 2;
    }
    return modes;
}
function checkStrong(pw){
    Modes=0;
    for (i=0;i<pw.length;i++){
        Modes|=CharMode(pw.charCodeAt(i));
    }
    return bitTotal(Modes);
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
