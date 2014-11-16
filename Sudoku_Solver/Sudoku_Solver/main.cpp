//
//  main.cpp
//  Sudoku_Solver
//
//  Created by Shuai Wang on 6/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveSudoku(vector<vector<char>> &board){
        for(int row = 0; row<9; row++){
            for(int column=0; column<9; column++){
                if(board[row][column] == '.'){
                    for(int tri = 0; tri<9; tri++){
                        board[row][column] = '1'+tri;
                        if(isValid(board, row, column) && solveSudoku(board)){
                            return true;
                        }
                        board[row][column] = '.';
                    }
                    
                    return false;
                }
            }
        }  // for the last number is not '.', you should return true here. Otherwise, it will return
        //false and the board will be empty.
        
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, int row, int column){
        for(int n =0; n<9; n++){
            if(board[row][n] == board[row][column] && n !=column)
                return false;
        }
        
        for(int m = 0; m<9; m++){
            if(board[m][column] == board[row][column] && m!=row)
                return false;
        }
        
        
        
        int rowMod = row/3;
        int columnMod = column/3;
        
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[rowMod*3+i][columnMod*3+j] == board[row][column] && rowMod*3+i != row && columnMod*3+j!=column){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    vector<vector<char>> board = {
        {'.', '.', '9', '7', '4', '8', '.', '.', '.' },
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.','2', '.', '1','.', '9', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};

    
    Solution s;
    s.solveSudoku(board);
    
    vector<vector<char>> :: iterator it = board.begin();
    for(; it!=board.end(); it++){
        vector<char> :: iterator it2 = it->begin();
        for(; it2!=it->end(); it2++){
            cout << *it2 << " ";
        
        }
        
        cout << endl;
    
    }
    
    return 0;
}

