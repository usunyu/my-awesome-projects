//
//  Person.hpp
//  CppBeginnerTutorial
//
//  Created by Yu Sun on 5/19/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>

using namespace std;

class Person {
private:
    string name;
    
public:
    Person();
    string toString();
    void setName(string newName);
    string getName();
};

#endif /* Person_hpp */
