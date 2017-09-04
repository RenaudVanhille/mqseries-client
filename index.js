const pub = require('./build/Release/mq_pub.node');

function SendPub(i) {
        return new Promise(
                (resolve, reject) => {
                        pub.send('message ' + i).then(
                                () => { setTimeout(() => { return SendPub(++i); }, 1000) },
                                (reason) => { reject(reason); }
                        );
                }
        );
}

pub.init('QM2', 'sport').then(() => {
    return SendPub(0).then(console.log, console.error)
    }, console.error);