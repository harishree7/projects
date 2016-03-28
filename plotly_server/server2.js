var serialport = require('serialport'),
    plotly = require('plotly')('harishree7','o16ech8edw'),
    token = '2sqgjdmvzk';

var portName = 'COM5';
var sp = new serialport.SerialPort(portName,{
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline("\r\n")
});

// helper function to get a nicely formatted date string
function getDateString() {
    var time = new Date().getTime();
    // 32400000 is (GMT+5.30 INDIA)
    // for your timezone just multiply +/-GMT by 3600000
    var datestr = new Date(time +19800000).toISOString().replace(/T/, ' ').replace(/Z/, '');
    return datestr;
}

var initdata = [{x:[], y:[], stream:{token:token, maxpoints: 500}}];
var initlayout = {fileopt : "extend", filename : "sensor-test"};

plotly.plot(initdata, initlayout, function (err, msg) {
    if (err) return console.log(err)

    console.log(msg);
    var stream = plotly.stream(token, function (err, res) {
        console.log(err, res);
    });

    sp.on('data', function(input) {
        if(isNaN(input) || input > 1023) return;

    var streamObject = JSON.stringify({ x : getDateString(), y : input });
    console.log(streamObject);
    stream.write(streamObject+'\n');
    });
});
