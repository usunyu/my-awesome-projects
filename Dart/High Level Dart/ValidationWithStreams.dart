import 'dart:html';
import 'dart:async';

void main() {
  final InputElement input = querySelector('input');
  final DivElement div = querySelector('div');
  
  final validator = new StreamTransformer.fromHandlers(
    handleData: (inputValue, sink) {
      if (inputValue.contains('@')) {
        sink.add(inputValue);
      } else {
        sink.addError('Email not valid!');
      }
    }
  );
  
  input.onInput
    .map((dynamic event) => event.target.value)
    .transform(validator)
    .listen(
        (input) {
        print('Thats email looks valid.');
        div.innerHtml = '';
      },
        onError: (err) {
        div.innerHtml = err;
      },
    );
}