//
//  main.cpp
//  ReverseCharInput
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution{

public:
    static vector<char> reverse(string &input){
        vector<char> result;
        for(int i=0; i<input.size();){
            //cout<< temt;
            stack<char> temp;
            if(!::isalnum(input.at(i))){ // if it is the space and comma ot whatever
                result.push_back(input[i]);
                i++;
                //continue;
            }else{// must be reversed
                if((input.at(i)>='a'&& input.at(i)<='z') || (input[i]>='A'&& input[i]<='Z')){
                    int j=i;
                   
                    while(j<input.size()&&::isalnum(input.at(j))){
                        temp.push(input.at(j));
                        j++;
                    }
                    while(!temp.empty()){
                        char tempChar = temp.top();
                        temp.pop();
                        result.push_back(tempChar);
                    }
                    i=j;//if add 1 here, space and comma will not be added
                }else if(input.at(i)>='0' && input.at(i)<='9'){ // if we find the number we need to check if there will be a char
                    int j=i;
                    int start = i;
                    
                    bool ifContainChar=false;
                    while(j<input.size()&&::isalnum(input.at(j))){
                        if(input.at(j)>='0' && input.at(j)<='9')
                            j++;
                        else{
                            ifContainChar = true;
                            j++;
                        }
                    }
                    
                    if(ifContainChar==false){
                        for(;start<j;start++){
                            result.push_back(input.at(start));
                        }
                    }else{
                        for(;start<j;start++){
                            temp.push(input.at(start));
                        }
                        while(!temp.empty()){
                            char tempChar = temp.top();
                            result.push_back(tempChar);
                            temp.pop();
                            
                        }
                    }
                    i=j;
                    
                }
            }
                
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    string s ="   knk knl 999";
    //cout << s.at(3);
    vector<char> result = Solution::reverse(s);
    for(vector<char> ::iterator it = result.begin(); it!=result.end();it++){
        cout << *it;
    }

    cout<<endl;
    return 0;
}

