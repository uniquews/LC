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
        if (s.size() == 0) {
            return vector<string> {};
        }
        
        string eachResult = "";
        vector<string> result;
        dfs(s, 0, 0, eachResult, result);
        return result;
    }
    
    void dfs(string s, int index, int num, string eachResult, vector<string> &result) {
        if (index == s.size() && num == 4) {
            result.push_back(eachResult);
            return;
        } else if (index == s.size() && num != 4) {
            return;
        } else if (index != s.size() && num == 4) {
            return;
        } else {
            if (s[index] == '0') {
                string old = eachResult;
                eachResult += s[index];
                if (num != 3) {
                    eachResult.append(".");
                }
                dfs(s, index + 1, num + 1, eachResult, result);
                eachResult = old;
            } else {
                for (int i = 1; i <= 3; i++) {
                    string old = eachResult;
                    if (index + i <= s.size()) {
                        string tmp = s.substr(index, i);
                        int number = stoi(tmp);
                        if (number > 0 && number <= 255) {
                            eachResult.append(tmp);
                            if (num != 3) {
                                eachResult.append(".");
                            }
                            dfs(s, index + i, num + 1, eachResult, result);
                            eachResult = old;
                        }
                        
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
    vector<string> result = s.restoreIpAddresses("1111");
    vector<string>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
        
    }
    
    cout << endl;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

