var express = require('express');
var app = express();
var fs = require("fs");

/* 
 * GET 
 * == Test: http://127.0.0.1:8082/listUsers
 */

app.get('/listUsers', function (req, res) {
   fs.readFile( __dirname + "/" + "users.json", 'utf8', function (err, data) {
       console.log( data );
       res.end( data );
   });
})


/* 
 * GET id 
 * == Test: http://127.0.0.1:8082/user/id=2
 */

app.get('/user/id=:id', function (req, res) {
   fs.readFile( __dirname + "/" + "users.json", 'utf8', function (err, data) {
       users = JSON.parse( data );
       var user = users["user" + req.params.id] 
       console.log( user );
       res.end( JSON.stringify(user));
   });
})

/* 
 * POST 
 * == Test: http://127.0.0.1:8082/addUser
 */

var user = {
   "user4" : {
      "name" : "mohit",
      "password" : "password4",
      "profession" : "teacher",
      "id": 4
   }
}

app.get('/addUser', function (req, res) {
   // First read existing users
   fs.readFile( __dirname + "/" + "users.json", 'utf8', function (err, data) {
       data = JSON.parse( data );
       // Insert user to data
       data["user4"] = user["user4"];
       console.log( data );
       res.end( JSON.stringify(data));
   });
})


/*
 * DELETE
 * == Test: http://127.0.0.1:8082/deleteUser
 */

var id = 2;
app.get('/deleteUser', function (req, res) {

   fs.readFile( __dirname + "/" + "users.json", 'utf8', function (err, data) {
       data = JSON.parse( data );
       // Delete user
       delete data["user" + 2];
       console.log( data );
       res.end( JSON.stringify(data));
   });
})


/* API server */
var server = app.listen(8082, function () {

  var host = server.address().address
  var port = server.address().port

  console.log("Example app listening at http://%s:%s", host, port)

})
