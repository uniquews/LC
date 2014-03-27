//
//  main.cpp
//  ValidParentheses
//
//  Created by Shuai Wang on 3/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution{
public:
    static bool Valid(vector<char> input){
        stack<char> std;
        if(input.size()==0) return false;// don't forget input is null
//        for(vector<char>::iterator it = input.begin(); it!=input.end(); it++){
//        }
        for(int i=0; i<input.size(); i++){
            if(input[i]=='(' || input[i]=='[' || input[i]=='{')
                std.push(input[i]);
            else{
                if(std.size()==0) //there is no { [ [, but ] } ) return false
                    return false;
                char temp = std.top();
                //cannot pop here null pointer
                
                if(input[i]=='}' && temp=='{'){
                    std.pop();
                    
                }else if(input[i]==')' && temp=='('){
                    
                    std.pop();
                }
  
                else if(input[i]==']' && temp=='['){
                    std.pop();
                }else{
                    return false;
                }
                
            }
        }
        
        if(std.size()!=0)// left parentheses will be more than the right parentheses
            return false;
        return true;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<char> input={'[','}'};

    bool result = Solution::Valid(input);
    std::cout << result<< endl;
    return 0;
}

