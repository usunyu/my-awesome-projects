void main() {
  var person = new Person('usunyu');
  
  person.printName();
}

class Person {
  String firstName;
  
  Person(this.firstName);

  printName() {
    print(firstName);
  }
}
