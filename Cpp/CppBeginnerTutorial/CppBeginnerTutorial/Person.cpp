//
//  Person.cpp
//  CppBeginnerTutorial
//
//  Created by Yu Sun on 5/19/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#include "Person.hpp"

Person::Person() {
    name = "Sun";
}

string Person::toString() {
    return "Person's name is: " + name;
}

void Person::setName(string newName) {
    name = newName;
}

string Person::getName() {
    return name;
}