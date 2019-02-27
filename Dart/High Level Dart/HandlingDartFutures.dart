import 'dart:async';

main() async {
  print('About to fetch data...');
  
//   get('http://data.com/list')
//     .then((result) {
//       print(result);
//     });
  
  var result = await get('http://data.com/list');
  
  print(result);
}

Future<String> get(String url) {
  return new Future.delayed(new Duration(seconds: 3), () {
    return 'Got the data!';
  });
}