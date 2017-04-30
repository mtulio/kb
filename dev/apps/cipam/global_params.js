/*
 * GLOBALs config
 */

/* Server Configuration - Globals */
var PORT = 8080

/* Server Configuration - File System */
var DocumentRoot = './public'
var index = DocumentRoot + '/index.htm'
var dir_data = './data'
var dir_conf = dir_data +'/config'

/* Export environments */
exports.PORT = PORT;
exports.DocumentRoot = DocumentRoot;
exports.index = index;
exports.dir_data = dir_data;
exports.dir_conf = dir_conf;

