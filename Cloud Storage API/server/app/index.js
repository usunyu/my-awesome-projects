var aws = require('aws-sdk'),
  http = require('http'),
  fs = require('fs'),
  path = require('path'),
  express = require('express');

var app = new express();

app.set('views', __dirname + '/views');
app.set('view engine', 'jade');
app.use(express.bodyParser());
app.use(express.static(path.join(__dirname, 'public')));

var config_path = path.join(__dirname, '../auth.json');

aws.config.loadFromPath(config_path);
var s3 = new aws.S3();

app.get('/file', function (req, res) {
  var options = {
    Bucket: 'faq_system',
    Key: req.param('name')
  };

  s3.getObject(options, function (err, data) {
    res.end(data.Body);
  });
});

app.get('/list', function (req, res) {
  s3.listObjects({Bucket: 'faq_system'}, function (err, data) {
    res.render('list', data);
  });
});

app.get('/buckets', function (req, res) {
  s3.listBuckets(function (err, data) {
    res.json(data);
  });
});

app.get('/upload', function (req, res) {
  res.render('upload');
});

app.post('/upload', function (req, res) {
  var s3request = {
    Body: fs.readFileSync(req.files.uploadedFile.path),
    Bucket: 'faq_system',
    Key: req.files.uploadedFile.name
  };

  s3.putObject(s3request, function (err, data) {
    res.render('upload', {done: true});
  });
});

module.exports = app;