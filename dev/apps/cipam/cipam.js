
/* GLOBALS */
var express = require('express'),
  path  = require("path");
//var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');

var app = express();

var global = require("./global_params.js")


/*  >>Init Web server<< */
//  engine setup [DISABLED]
//app.set('views', path.join(__dirname, 'views'));
//app.set('view engine', 'jade');

// Show pages and stats
app.use(logger('dev'));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

// Cookies
app.use(cookieParser());

/* Use static files and set DocumentRoot */
//app.use(require('stylus').middleware(path.join(__dirname, global.DocumentRoot)));
app.use(express.static(path.join(__dirname, global.DocumentRoot)));

//app.listen(process.env.PORT || 3000);
/*var server = app.listen(global.PORT, function () {

  var host = server.address().address
  var port = server.address().port

  console.log("Server listening at http://%s:%s", host, port)

})*/



/* >>ROUTES<< */
var route_index = require('./routes/index');
var route_api = require('./routes/api');

app.use('/', route_index);
app.use('/api', route_api);

/* >>Error pages<< */

/* >>FINISH<<*/
module.exports = app;
