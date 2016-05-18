//
//  main.cpp
//  CppBeginnerTutorial
//
//  Created by Yu Sun on 5/18/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    cout << "(Lec 4, Hello World C++)" << endl;
    cout << "Hello, World!" << endl;
    cout << "=======================================" << endl;

    cout << "(Lec 22, Arrays - Lists of Data)" << endl;
    int values[3] = {2, 4, 8};
    cout << "val 0: " << values[0] << endl;
    cout << "val 1: " << values[1] << endl;
    cout << "val 2: " << values[2] << endl;
    cout << "val 3 (bad): " << values[3] << endl;
    cout << "=======================================" << endl;

    cout << "(Lec 25, Sizeof Multidimensional Arrays)" << endl;
    string animals[][3] = {
        {"fox", "dog", "cat"},
        {"mouse", "tiger", "lion"},
    };
    cout << "sizeof(animals): " << sizeof(animals) << endl;
    cout << "sizeof(string): " << sizeof(string) << endl;
    cout << "=======================================" << endl;

    return 0;
}
