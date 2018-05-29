
let http = require("http");

http.createServer((req, res) => {
    res.writeHead(200, {"Content-Type": "application/json"});
    let json = JSON.stringify("success");
    res.end("success_jsonpCallback(" + json + ")");

}).listen('4497');