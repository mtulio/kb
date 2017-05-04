var express = require('express');
var router = express.Router();
var fs = require("fs");
var  url   = require("url");
var  path  = require("path");

var global = require("../global_params.js")


/* GET home page. */
router.get('/', function (request, response) {

  var uri = url.parse(request.url).pathname;
  //console.log("Uri received: %s", uri)

  if (uri == '/') { uri = global.index; }
  //console.log("Uri received: %s", uri)

  var filename = path.join(process.cwd(), uri);
  path.exists(filename, function(exists) {

    if (!exists) {
      response.writeHead(404, {"Content-Type": "text/plain"});
      response.end("404 Not Found\n");
      return;
    }

    //console.log("Reading file: " + uri);
    fs.readFile(filename, "binary", function(err, file) {
      if (err) {
        response.writeHead(500, {"Content-Type": "text/plain"  });
        response.end(err+ "\n");
        return;
      }
      response.writeHead(200);
      response.end(file, "binary");
    });
  });
})

module.exports = router;
