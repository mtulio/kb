/*
 * REST API
 *
 * URI:
 * - /api
 * --- /getConfig
 * --- /getConfigNets
 * --- /getConfigNet?name=NETNAME
 * --- /getConfigBacks
 * --- /getConfigBacks?name=BACKNAME
 * --- /getNet?name=NETNAME
 * --- /getNetIP?&netname=NETNAME&name=NETNAME
 * --- /exec --> ROUTING
 * 
 */

/* GLOBALS */
var express = require('express');
var router = express.Router();
var fs = require("fs"),
  url = require("url"),
  http = require("http");

var global = require("../global_params.js")

var base_uri = '/api'

/* ROUTES */

var route_api_exec = require('./api_exec');
router.use('/exec', route_api_exec);

/* REST */
/* == curl -X GET -s http://localhost:8080/api/getConfigNets | python -mjson.tool */
router.get('/getConfigNets', function (req, res) {
  console.log( "GET %s: %s", base_uri, url.parse(req.url).pathname);
  fs.readFile( global.dir_conf + "/networks.json", 'utf8', function (err, data) {
    res.end( data );
  });
})

router.get('/getConfigNets2', function(req, res) {

  var url = 'http://graph.facebook.com/517267866/?fields=picture';
  var fbResponse;
  http.get(url, function(res){
    var body = '';

    res.on('data', function(chunk){
        body += chunk;
    });

    res.on('end', function() {
        fbResponse = JSON.parse(body);
        //console.log("Got a response: ", fbResponse.picture);
        req.write( fbResponse.picture );
	req.end();
    });
  }).on('error', function(e){
      console.log("Got an error: ", e);
  });
})


module.exports = router;
