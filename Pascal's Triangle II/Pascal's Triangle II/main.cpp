//
//  main.cpp
//  Pascal's Triangle II
//
//  Created by Shuai Wang on 6/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        
        for(int i = 0; i <= rowIndex; i++){
            if(i == 0){
                last.push_back(1);
            }else{
                vector<int> :: iterator it = last.begin();
                last.insert(it, 0);
                last.push_back(0);
                for(int j = 0; j <= i; j++){
                    last[j] = last[j] + last[j + 1];
                }
                
                last.pop_back();
            }
        }
        
        
        return last;
    }
    
};

int main(int argc, const char * argv[])
{

    
    return 0;
}

