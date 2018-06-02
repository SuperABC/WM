
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

let fs = require("fs");
let dict = new Buffer(10436608);
let words = [];
fs.open("src/dict.all", "r", function(err, fd){
    fs.read(fd, dict, 0, dict.length, 0, function(err, bytes){
        let entries = dict.toString().split('####');
        entries.forEach(function(item){
            let cont = item.split('$$$$');
            words.push({word:cont[0], trans:cont[1], examp:cont[2]});
        });
        console.log("read finished.");
    });
});

function handle(data, res){
    if(data[1]==="login_req"){
        let queryStr = 'select * from users where id = \'' + data[2] + '\' and password = \'' + data[3] + '\';';
        connection.query(queryStr, function(err, rows) {
            if (err) console.log(err);
            if(rows.length>0) {
                res.writeHead(200, {'Content-Type': 'application/json'});
                let json = JSON.stringify('success');
                res.end('success_jsonpCallback(' + json + ')');
            }
        });
    }
    else if(data[1]==="sign_req"){
        let queryStr = 'select * from users where id = \'' + data[2] + '\' and password = \'' + data[3] + '\';';
        connection.query(queryStr, function(err, rows) {
            if (err) console.log(err);
            if(rows.length>0) {
                res.writeHead(200, {'Content-Type': 'application/json'});
                let json = JSON.stringify('redef');
                res.end('success_jsonpCallback(' + json + ')');
            }
            else{
                let signStr = 'insert into users values (\'' + data[2] + '\', \'' + data[3] + '\');';
                connection.query(signStr, function(err) {
                    if (err) console.log(err);
                    res.writeHead(200, {'Content-Type': 'application/json'});
                    let json = JSON.stringify('success');
                    res.end('success_jsonpCallback(' + json + ')');
                });
            }
        });
    }
    else if(data[1]==="tour_req"){
        res.writeHead(200, {'Content-Type': 'application/json'});
        let json = JSON.stringify('success');
        res.end('success_jsonpCallback(' + json + ')');
    }
    else if(data[1]==="word_search"){
        res.writeHead(200, {'Content-Type': 'application/json'});
        let json = JSON.stringify(wordSearch(data[2]));
        res.end('success_jsonpCallback(' + json + ')');
    }
    else if(data[1]==="find_plan"){
        let queryStr = 'select wordset from milestone where id = \'' + data[2] + '\';';
        connection.query(queryStr, function(err, rows) {
            if (err) console.log(err);
            if(rows.length>0) {
                res.writeHead(200, {'Content-Type': 'application/json'});
                let json = JSON.stringify(rows[0].milestone);
                res.end('success_jsonpCallback(' + json + ')');
            }
        });
    }
    else if(data[1]==="add_plan"){
        let queryStr = 'insert into milestone values(\'' + data[2] + '\', \'' + data[2] + '\', 0, 8);';
        connection.query(queryStr, function(err, rows) {
            if (err) console.log(err);
            res.writeHead(200, {'Content-Type': 'application/json'});
            let json = JSON.stringify("success");
            res.end('success_jsonpCallback(' + json + ')');
        });
    }
    else if(data[1]==="fetch_plan"){
        let queryStr1 = 'select wordset, base from milestone where id = \'' + data[2] + '\';';
        connection.query(queryStr1, function(err, wordbase) {
            if (err) console.log(err);
            if(wordbase.length>0) {
                let queryStr2 = 'select word from ' + wordbase[0].wordset + ' where num >= ' + wordbase[0].base + ' and num < ' + wordbase[0].base + '+8;';
                connection.query(queryStr2, function(err, contents) {
                    if (err) console.log(err);
                    if(contents.length>0) {
                        console.log(contents);
                        res.writeHead(200, {'Content-Type': 'application/json'});
                        let json = JSON.stringify(contents);
                        res.end('success_jsonpCallback(' + json + ')');
                    }
                });
            }
        });
    }
}

function searchMeet(iter, feed){
    if(feed==="*")return true;
    if(feed.length===0&&iter.length===0)return true;
    if(feed.indexOf("*")===0){
        while(!iter.length===0){
            if(searchMeet(iter = iter.substr(1), feed.substr(1)))
                return true;
        }
    }
    if(iter.length===0) return false;
    if(feed.indexOf("?")===0 || feed[0]===iter[0]){
        return searchMeet(iter.substr(1), feed.substr(1));
    }
}

function wordSearch(word){
    if(word.indexOf('*')>=0||word.indexOf('?')>=0)return multiSearch(word.toLowerCase());
    return singleSearch(word.toLowerCase(), 0, words.length);
}
function singleSearch(word, begin, end){
    if(begin>=end-1){
        if(word===words[begin].word)return JSON.stringify(words[begin]);
        return JSON.stringify("");
    }
    if(word===words[Math.floor((begin+end)/2)].word.toLowerCase())return JSON.stringify(words[Math.floor((begin+end)/2)]);
    else if(word > words[Math.floor((begin+end)/2)].word.toLowerCase())return singleSearch(word, Math.floor((begin+end)/2), end);
    else return singleSearch(word, begin, Math.floor((begin+end)/2));
}
function multiSearch(word){
    let res = [];
    words.forEach(function(item){
        if(searchMeet(item.word, word))
            res.push(item);
    });
    return JSON.stringify(res);
}


