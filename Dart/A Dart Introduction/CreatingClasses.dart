void main() {
  var person = new Person();
  
  person.firstName = 'usunyu';
  
  person.printName();
}

class Person {
  String firstName;

  printName() {
    print(firstName);
  }
}
