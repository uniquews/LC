//
//  main.cpp
//  test_copy
//
//  Created by Shuai Wang on 3/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using  namespace std;
class test{
public:
    static void swap(int x, int y){
        int temp = x;
        x =y;
        y =temp;
        return;
    
    }

};


int main(int argc, const char * argv[])
{

    // insert code here...
    int x=6;
    int y=7;
    y=x;
    y++;
    cout<< x;
    cout<<y;
//    cout<< x << " " << y<< endl;
//    test::swap(x, y);
//    cout<< x << " " << y<<endl;
    return 0;
}

