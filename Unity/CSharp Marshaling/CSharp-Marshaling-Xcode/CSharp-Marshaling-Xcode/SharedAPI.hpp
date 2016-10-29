//
//  SharedAPI.hpp
//  CSharp-Marshaling-Xcode
//
//  Created by Yu Sun on 10/29/16.
//  Copyright © 2016 Yu Sun. All rights reserved.
//

#ifndef SharedAPI_hpp
#define SharedAPI_hpp

#include <stdio.h>

class SharedAPI {
    int id;
public:
    SharedAPI(int id);
    ~SharedAPI();
    
    int MyIdPlusTen();
    int** GetArray();
};

extern "C" {
    int Add(int a, int b);
    void CallMe(void(*action)(int value));
    SharedAPI* CreateSharedAPI(int id);
    int GetMyIdPlusTen(SharedAPI* api);
    void DeleteSharedAPI(SharedAPI* api);
    
    int** GetArray(SharedAPI* api);
    void DeleteArray(int** myArray);
}

#endif /* SharedAPI_hpp */
