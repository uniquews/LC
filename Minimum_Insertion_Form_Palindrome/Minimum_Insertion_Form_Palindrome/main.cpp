//
//  main.cpp
//  Minimum_Insertion_Form_Palindrome
//
//  Created by Shuai Wang on 8/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinInsertion(string &str) {
        
        if (str.size() == 0) {
            return 0;
        }
        
        int num = (int)str.size();
        vector<vector<int>> table (num, vector<int> (num, -1));
        
        for (int i = 0; i < num; i++) {
            table[i][i] = 0;
        }
        
        for (int i = 0; i < num - 1; i++) {
            if (str[i] == str[i + 1]) {
                table[i][i + 1] = 0;
            } else {
                table[i][i + 1] = 1;
            }
        }
        
        for (int i = num - 1; i >= 0; i--) {
            for (int j = i; j < num; j++) {
                if (j - i < 2) {
                    continue;
                }
                
                if (str[i] == str[j]) {
                    table[i][j] = table[i + 1][j - 1];
                } else {
                    table[i][j] = min(table[i][j - 1], table[i + 1][j]) + 1;
                }
            }
        }
        
        return table[0][num - 1];
    
    }

};

int main(int argc, const char * argv[])
{
    Solution su;
    string str1 = "geeks";
    string str2 = "skgeegks";
    string str3 = "";
    string str4 = "ab";
    string str5 = "aa";
    string str6 = "abcd";
    string str7 = "cbcda";
    
    int num;
    cin >> num;
    
    
    string str8 = "abcde";
    cout << su.findMinInsertion(str1) << endl;
    cout << su.findMinInsertion(str2) << endl;
    cout << su.findMinInsertion(str3) << endl;
    cout << su.findMinInsertion(str4) << endl;
    cout << su.findMinInsertion(str5) << endl;
    cout << su.findMinInsertion(str6) << endl;
    cout << su.findMinInsertion(str7) << endl;
    cout << su.findMinInsertion(str8) << endl;
    return 0;
    
    
// 3
// 0
// 0
// 1
// 0
// 3
// 2
// 4
}

