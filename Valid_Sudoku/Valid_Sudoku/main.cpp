//
//  main.cpp
//  Valid_Sudoku
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        //   bool used[9];
        vector<bool> used(9, false);
        
        for (int i = 0; i < 9; ++i) {
            fill(used.begin(), used.begin()+9, false);
            for(int j=0;j<9;++j)// 检查行
                if (!check(board[i][j], used))
                    return false;
            
            fill(used.begin(), used.begin()+9, false);
            for(int j=0;j<9;++j)// 检查列
                if (!check(board[j][i], used))
                    return false;
        }
        
        for(int r=0;r<3;++r)// 检查 9 个子格子
            for (int c = 0; c < 3; ++c) {
                fill(used.begin(), used.begin()+9, false);
                for (int i = r * 3; i < r * 3 + 3; ++i)
                    for (int j = c * 3; j < c * 3 + 3; ++j)
                        if (!check(board[i][j], used))
                            return false;
            }
        return true;
    }
    
    bool check(char ch, vector<bool> &used) {
        if (ch == '.') return true;
        if (used[ch - '1']) return false;
        used[ch - '1'] = true;
        return true;
    }
    
    
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

