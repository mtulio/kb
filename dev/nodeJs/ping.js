var sys = require('sys')
var exec = require('child_process').exec;
function puts(error, stdout, stderr) { sys.puts(stdout) }
exec("ping -c 2 localhost >/dev/null 2>&1 && echo -n $?", puts);
