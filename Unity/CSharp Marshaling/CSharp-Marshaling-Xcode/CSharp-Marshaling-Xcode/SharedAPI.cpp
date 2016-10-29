//
//  SharedAPI.cpp
//  CSharp-Marshaling-Xcode
//
//  Created by Yu Sun on 10/29/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#include "SharedAPI.hpp"

int Add(int a, int b) {
    return a + b;
}

void CallMe(void(*action)(int value)) {
    action(42);
}

int GetMyIdPlusTen(SharedAPI* api) {
    return api->MyIdPlusTen();
}

void DeleteSharedAPI(SharedAPI* api) {
    delete api;
}

int** GetArray(SharedAPI* api) {
    return api->GetArray();
}

void DeleteArray(int** myArray) {
    for (int i = 0; i < 10; i++) {
        delete [] myArray[i];
    }
    delete [] myArray;
}

SharedAPI* CreateSharedAPI(int id) {
    return new SharedAPI(id);
}

SharedAPI::SharedAPI(int id): id(id) {
    
}

SharedAPI::~SharedAPI() {
    
}

int SharedAPI::MyIdPlusTen() {
    return Add(id, 10);
}

int** SharedAPI::GetArray() {
    int** myArray = new int*[10];
    for (int i = 0; i < 10; i++) {
        myArray[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            myArray[i][j] = i * j + 10;
        }
    }
    return myArray;
}
