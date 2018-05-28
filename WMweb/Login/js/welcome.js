
var xmlHttpRequest;    
  
function createXmlHttpRequest(){    
    if(window.ActiveXObject){ //如果是IE浏览器    
        return new ActiveXObject("Microsoft.XMLHTTP");    
    }else if(window.XMLHttpRequest){ //非IE浏览器    
        return new XMLHttpRequest();    
    }    
}    
    
function onLogin(){
    var url = "http:\\\\www.baidu.com";
             
    xmlHttpRequest = createXmlHttpRequest();    
        
    xmlHttpRequest.onreadystatechange = function(){
        if(xmlHttpRequest.readyState == 4 && xmlHttpRequest.status == 200){    
            var b = xmlHttpRequest.responseText;    
            if(b == "true"){    
                alert("登录成功！");    
            }else{    
                alert("登录失败！");    
            }           
        }    
    }
          
    xmlHttpRequest.open("POST",url,true);    
        
    xmlHttpRequest.send(null);      
}       
    
    

function login(){
    //sendHttpRequest('http:\\127.0.0.1:4497', 'get', null, null);
    onLogin();
    //window.open('../Main/user.html');
    //window.close();
}
function signup(){
    window.open('sign.html');
    window.close();
}
function tourvisit(){
    window.open('search.html');
    window.close();
}