var app = require('./app'),
  http = require('http');

http.createServer(app).listen(3000, function(){
  console.log('Server listening on port 3000');
});