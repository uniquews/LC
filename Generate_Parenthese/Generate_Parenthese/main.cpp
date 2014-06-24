//
//  main.cpp
//  Generate_Parenthese
//
//  Created by Shuai Wang on 6/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        string str;
        int numOfLeft = 0;
        int numOfRight = 0;
        dfs(n, str, numOfLeft, numOfRight, result);
        return result;
    }
    
    
    void dfs(int n, string &str, int numOfLeft, int numOfRight, vector<string> &result){
        if(numOfLeft == numOfRight && numOfLeft == n){
            result.push_back(str);
            return;
        }
        
        if(numOfLeft < n){
            str.append("(");
            numOfLeft++;
            dfs(n, str, numOfLeft, numOfRight, result);
            str.pop_back();
            numOfLeft--;
      
        }
        
        
        if(numOfLeft > numOfRight){
            str.append(")");
            numOfRight++;
            dfs(n, str, numOfLeft, numOfRight, result);
            str.pop_back();
            numOfRight--;
        
        }
        
        return;
    
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    vector<string> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
    
    }
    
    
    cout << endl;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

