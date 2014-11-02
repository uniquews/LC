//
//  main.cpp
//  Simply Path
//
//  Created by Shuai Wang on 11/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
class Solution {
public:
    string simplifyPath(string path) {
        if (path[0] != '/') {
            return "";
        }
        
        string result = "";
        vector<string> stk;
        int i = 0;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') {
                i++;
            }
            
            if (i == path.size()) {
                break;
            }
            int start = i;
            while (i < path.size() && path[i] != '/') {
                i++;
            }
            
            string tmp = path.substr(start, i - start);
            if (tmp == "..") {
                if (stk.size() != 0) {
                    stk.pop_back();
                }
            } else if (tmp != ".") {
                stk.push_back(tmp);
            }
            
        }
        
        if (stk.size() == 0) {
            return "/";
        } else {
            for (int i = 0; i < stk.size(); i++) {
                result.append("/").append(stk[i]);
            }
        }
        return result;
    }
    
};

int main(int argc, const char * argv[]) {
    string path = "/a/./b/../../c/";
    Solution su;
    cout << su.simplifyPath(path) << endl;
    return 0;
}
