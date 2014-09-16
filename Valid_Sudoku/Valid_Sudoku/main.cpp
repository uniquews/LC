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
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (isValid(board, i, j) == false) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, int row, int column) {
        for (int i = 0; i < 9; i++) {
            if (column != i && board[row][column] == board[row][i]) {
                return false;
            }
        }
        
        
        for (int i = 0; i < 9; i++) {
            if (row != i && board[row][column] == board[i][column]) {
                return false;
            }
        }
        
        int rowMod = row / 3;
        int colMod = column / 3;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (row != rowMod * 3 + i && column != colMod * 3 + j && board[row][column] == board[rowMod * 3 + i][colMod * 3 + j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[])
{
    vector<vector<char>> board = {{'.','.','.','.','.','.','.','.','2'},
                                {'.','.','.','.','.','.','6','.','.'},
                                {'.','.','1','4','.','8','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','.','.','.','.','.'},
                                {'.','.','.','.','3','.','.','.','.'},
                                {'5','.','8','6','.','.','.','.','.'},
                                {'.','9','.','.','.','.','4','.','.'},
                                {'.','.','.','.','5','.','.','.','.'}
        
    };
    
    Solution su;
    cout << su.isValidSudoku(board) << endl;
    return 0;
}

