/*
 * REST API
 *
 * URI:
 * - /api
 * --- /exec
 * ----- /ping?host=(HOSTNAME|IP)
 * ----- /scan?host=(HOSTNAME|IP)
 * 
 */

/* GLOBALS */
var express = require('express');
var router = express.Router();
var fs = require("fs"),
  url = require("url");

var global = require("../global_params.js")

var base_uri = '/api/exec'

/* ROUTES */


/* REST */
/* == /api/configNetworks */
router.get('/', function (req, res) {
  console.log( "GET %s: %s", base_uri, url.parse(req.url).pathname);
})

router.get('/ping', function (req, res) {
  console.log( "GET %s/ping: %s", base_uri, url.parse(req.url).pathname);
})


module.exports = router;
