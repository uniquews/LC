//
//  main.cpp
//  PaLindrome_Partitioning
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        vector<string> eachLevel;
        
        dfs(s, 0, (int)s.size()-1, eachLevel, result);
        
        return result;
    }
    
    void dfs(string s, int start, int end, vector<string> &eachLevel, vector<vector<string>> &result){
        
        if(start == end+1){
//            eachLevel.push_back(s.substr(start, 1));
            result.push_back(eachLevel);
//            eachLevel.pop_back();
            return;
        }
        
        for(int _start = start; _start <=end; _start++){
            if(isPP(s, start, _start)){
                eachLevel.push_back(s.substr(start, _start-start+1));

                dfs(s, _start+1, end, eachLevel, result);

                
                eachLevel.pop_back();
                //result.push_back(eachLevel);
            }
        }
        
        
        
        return;
    
    }
    
    
    
    bool isPP(string s, int start, int tempEnd){
        while(start <=tempEnd){
        
            if(s[start]  != s[tempEnd]){
                return false;
            }else{
                start ++;
                tempEnd--;
            
            }
        }
        return true;
    }

};

int main(int argc, const char * argv[])
{

    
    string str = "b";
    Solution s;
    vector<vector<string>> result = s.partition(str);
    
    vector<vector<string>>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<string>::iterator it2 = it->begin();
        for(; it2!=it->end();it2++){
        
            cout << *it2<< " ";
        }
        
        cout << endl;
    
    }
    
    return 0;
}

