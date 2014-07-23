//
//  main.cpp
//  Reverse_String
//
//  Created by Shuai Wang on 7/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        string rs="";
        for(int i=s.size()-1; i>=0;){
            while(i>=0 && s[i] == ' ') i--;
            if(i<0) break; // if we don.t add this, when finishing, because rs is not null, alg will add leading space. must be break,, no return!! because s should be equal to rs
            if(!rs.empty())
                rs.push_back(' ');
            string t;
            while(i>=0 && s[i] != ' ')
                t.push_back(s[i--]);
            reverse(t.begin(), t.end());
            rs.append(t);
        }
        s = rs;
    }
};

int main(int argc, const char * argv[])
{

    
    return 0;
}

