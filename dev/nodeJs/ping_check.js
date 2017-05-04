var fs = require('fs');

var ipAddr = {
  ipAddr:'127.0.0.1',
  ipStat:'NA',
  ipPorts:'NA'
}
var outputFilename = '/tmp/my.json';

// Ping
var exec = require('child_process').exec, child;
child = exec('ping -c 1 ', [ipAddr.ipAddr], function(error, stdout, stderr, callback) {
     if(error !== null) {
		ipAddr.ipStat = 'OFF'
	        console.log(ipAddr.ipAddr, "Not available: ", ipAddr.ipStat);
	}
	else {
		ipAddr.ipStat = 'ON'
        	console.log(ipAddr.ipAddr, "Available: ", ipAddr.ipStat);
        }
  // callback( ipAddr );
})
;

ipAddr.ipStat = 'NA2';
child.unref();
console.log("Stat: ", ipAddr.ipAddr, ipAddr.ipStat);
// Wait for children

fs.writeFile(outputFilename, JSON.stringify(ipAddr, null, 4), function(err) {
    if(err) {
      console.log(err);
    } else {
      console.log("JSON saved to " + outputFilename);
    }
}); 

