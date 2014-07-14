//
//  main.cpp
//  Sort_Color
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0; // from left to right, the first one is not red
        int blue = n-1; // from right to left, the first one is not blue
        
        for(int i=0; i<=blue;){
            if(A[i] == 0){
                swap(A[i++], A[red++]);
            }else if(A[i] == 2){
                swap(A[i], A[blue--]);
            }else{
                i++;
            }
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

