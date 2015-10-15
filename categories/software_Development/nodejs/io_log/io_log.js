#!/usr/bin/env node

/* Program to use Library (FS) */

/* Using library 'fs' */
var fs = require('fs');

/* Define filename */
var logfile = "io_out.log";

/* Define msg */
var msg = "# First stdout to log using nodejs. Hello MTulio. :)\n";

/* Write log to a file[logifle] 
 * writeFileSync is a function from a built-in filesystem library */
fs.writeFileSync(logfile, msg);

/* Show message in console (stdout) 
 * OBS.: __filename is a built-in convention that is a variable with the path of the current file
 * */
console.log(" Script: " + __filename + "\n Wrote : " + msg + "     To: " + logfile);
