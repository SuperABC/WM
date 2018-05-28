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

function login(){
    var socket = new WebSocket('http://localhost:4497');

    socket.onopen = function(event) { 

        socket.send('I am the client and I\'m listening!'); 
      
        socket.onmessage = function(event) { 
          console.log('Client received a message',event); 
        }; 
      
        socket.onclose = function(event) { 
          console.log('Client notified socket has closed',event); 
        }; 
    }; 
}