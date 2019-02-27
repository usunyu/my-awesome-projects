import 'package:flutter/material.dart';
import 'package:http/http.dart' show get;

class App extends StatefulWidget {
  createState() {
    return AppState();
  }
}

class AppState extends State<App> {
  int counter = 0;

  void fetchImage() {
    counter += 1;
    get('https://jsonplaceholder.typicode.com/photos/$counter');
  }

  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Text('$counter'),
        floatingActionButton: FloatingActionButton(
          child: Icon(Icons.add),
          onPressed: fetchImage,
        ),
        appBar: AppBar(
          title: Text("Let's see some images!"),
        ),
      ),
    );
  }
}