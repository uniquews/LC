//
//  main.cpp
//  Length_Of_Last_Word
//
//  Created by Shuai Wang on 8/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int count =0;

        for(int i=(int)strlen(s)-1; i>=0; i--){
            if(::isalnum(s[i])){
                count++;
            }else{
                if(count == 0)
                    continue;
                else
                    return count;
            }
        }
        
        return count;
    }
};

int main(int argc, const char * argv[])
{

    char *s = "b a";
    Solution su;
    cout << su.lengthOfLastWord(s) << endl;
    return 0;
}

