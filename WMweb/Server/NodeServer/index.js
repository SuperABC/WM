
let http = require('http');

http.createServer((req, res) => {
    handle(req.url.split('&'), res);
}).listen('4497');

let mysql = require('mysql');
let connection = mysql.createConnection({
    host: '127.0.0.1',
    user: 'root',
    password: 'wangyilin',
    database: 'wordmember',
    port: '3306'
});

function handle(data, res){
    if(data[1]==="login_req"){
        let queryStr = 'select * from users where id = \'' + data[2] + '\' and password = \'' + data[3] + '\';';
        connection.query(queryStr, function(err, rows) {
            if (err) throw err;
            if(rows.length>0) {
                res.writeHead(200, {'Content-Type': 'application/json'});
                let json = JSON.stringify('success');
                res.end('success_jsonpCallback(' + json + ')');
            }
        });
    }
}


