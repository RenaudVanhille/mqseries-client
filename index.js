const pub = require('./build/Release/mq_pub.node');
console.log(pub);
function SendPub(i) {
        return new Promise(
                (resolve, reject) => {
                        pub.publish('message ' + i).then(
                                () => { setTimeout(() => { return SendPub(++i); }, 1000) },
                                (reason) => { reject(reason); }
                        );
                }
        );
}

pub.init('QM1', 'sport').then(() => {
    return SendPub(0).then(console.log, console.error)
    }, console.error);

var http = require('http');

var server = http.createServer(function(req, res) {
    res.writeHead(200);
    res.end('Salut tout le monde !');
});
server.listen(8080);