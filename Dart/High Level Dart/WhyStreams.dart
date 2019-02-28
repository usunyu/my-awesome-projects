import 'dart:html';

void main() {
  final ButtonElement button = querySelector('button');
  
  button.onClick
    .timeout(
        new Duration(seconds: 1),
        onTimeout: (sink) => sink.addError("Too slow, you lost!"),
    )
    .listen(
        (event) {
        print("You clicked!");
      },
        onError: (err) => print(err),
    );
}