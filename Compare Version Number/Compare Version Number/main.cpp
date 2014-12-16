//
//  main.cpp
//  Compare Version Number
//
//  Created by Shuai Wang on 12/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = (int)version1.size();
        int n = (int)version2.size();
        
        int i = 0;
        int j = 0;
        
        int v1 = 0;
        int v2 = 0;
        
        while (i < m && j < n) {
            while (i < m && version1[i] != '.') {
                v1 = v1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < n && version2[j] != '.') {
                v2 = v2 * 10 + version2[j] - '0';
                j++;
            }
            
            if (v1 > v2) {
                return 1;
            }
            
            if (v1 < v2) {
                return -1;
            }
            
            v1 = 0;
            v2 = 0;
            
            i++;
            j++;
            
        }
        
        
        while (i < m && version1[i] != '.') {
            v1 = v1 * 10 + version1[i] - '0';
            i++;
        }
        while (j < n && version2[j] != '.') {
            v2 = v2 * 10 + version2[j] - '0';
            j++;
        }
        
        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        } else {
            return 0;
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    string version1 = "1.1";
    string version2 = "1.01";
    
    Solution su;
    cout << su.compareVersion(version1, version2) <<endl;
    
    
    return 0;
}
