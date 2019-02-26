import 'package:flutter/material.dart';

void main() {
  var app = MaterialApp(
    home: Scaffold(
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.add),
        onPressed: () {
          print('Hello worlds!');
        },
      ),
      appBar: AppBar(
        title: Text("Let's see some images!"),
      ),
    ),
  );

  runApp(app);
}