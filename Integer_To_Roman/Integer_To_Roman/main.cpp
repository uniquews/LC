//
//  main.cpp
//  Integer_To_Roman
//
//  Created by Shuai Wang on 7/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char symbol[7] = {'I', 'V','X','L','C','D', 'M'};
        int digit=0;
        int scale = 1000;
        string result;
        
        //every two char is a level.
        for(int i=6; i>=0; i-=2){
            digit = num/scale;
            
            if(digit!=0){
                
                if(digit <=3){
                    result.append(digit, symbol[i]);
                }else if(digit == 4){
                    result.append(1, symbol[i]);
                    result.append(1, symbol[i+1]);
                }else if(digit == 5){
                    result.append(1, symbol[i+1]);
                }else if(digit <= 8){
                    result.append(1, symbol[i+1]);
                    result.append(digit-5, symbol[i]);
                }else if(digit == 9){
                    result.append(1, symbol[i]);
                    result.append(1, symbol[i+2]);
                }
                
            }
            
            
            
            num = num%scale;
            scale = scale/10;
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    int num = 3469;
    Solution su;
    cout << su.intToRoman(num)<<endl;
    return 0;
}

