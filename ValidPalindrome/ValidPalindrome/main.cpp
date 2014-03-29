//
//  main.cpp
//  ValidPalindrome
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    static bool isPalindrome(string s){
        // be used to using auto
        //know transform function
        transform(s.begin(), s.end(), s.begin(),::tolower);
        auto start = s.begin();// this return a iterator
        auto last = prev(s.end());
        while(start<last){// equal situation doesn't need to check, same char
            if(!isalnum(*start)){
                start++;
                continue;
            }
            if(!isalnum(*last)){
                last--;
                continue;
            }
            if(*start==*last){
                start++;
                last--;
            }else{
                return false;
            }
        
        
        }
        
        return true;
    }

};


int main(int argc, const char * argv[])
{

    // insert code here...
    string s="A man, a plan, a canal: Panama";
    bool result = Solution::isPalindrome(s);
    std::cout << result<< endl;
    return 0;
}

