import 'dart:convert';

void main() {
  var rawJson = '{"url": "http://blah.jpg", "id": 1}';
  
  var parsedJson = json.decode(rawJson);
//   print(parsedJson["url"]);
//   var imageModel = ImageModel(parsedJson['id'], parsedJson['url']);
  var imageModel = ImageModel.fromJson(parsedJson);
  
  print(imageModel.url);
}

class ImageModel {
  int id;
  String url;
  
  ImageModel(this.id, this.url);
  
  ImageModel.fromJson(parsedJson) {
    id = parsedJson['id'];
    url = parsedJson['url'];
  }
}