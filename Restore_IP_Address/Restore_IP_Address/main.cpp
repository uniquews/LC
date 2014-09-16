//
//  main.cpp
//  Restore_IP_Address
//
//  Created by Shuai Wang on 6/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string str = "";
        dfs(s, 0, result, str, 0);
        return result;
    }
    
    void dfs(string s, int start, vector<string> &result, string &str, int step) {
        if (start == s.size() && step == 4) {
            result.push_back(str);
            return;
        } else if (start == s.size() && step != 4) {
            return;
        } else if (start != s.size() && step == 4) {
            return;
        } else {
            for (int i = start; i < start + 3 && i < s.size(); i++) {
                
                if (s[start] == '0') {
                    string tmp = s.substr(start, 1);
                    string origin = str;
                    if (step == 3) {
                        str.append(tmp);
                    } else {
                        str.append(tmp).append(".");
                    }
                    dfs(s, start + 1, result, str, step + 1);
                    str = origin;
                    break;
                } else {
                    string tmp = s.substr(start, i - start + 1);
                    int tmpNum = stoi(tmp);
                    string origin = str;
                    if (tmpNum >= 0 && tmpNum <= 255) {
                        if (step == 3) {
                            str.append(tmp);
                        } else {
                            str.append(tmp).append(".");
                        }
                        
                        dfs(s, i + 1, result, str, step + 1);
                        str = origin;
                    }
                
                }
            
                
            }
     
        
        }
       
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    Solution s;
    vector<string> result = s.restoreIpAddresses("010010");
    vector<string>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
    
    }
    
    cout << endl;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

