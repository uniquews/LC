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

    
    bool solveSudoku( vector<vector<char>> &board){
        for(int m =0; m<9; m++){
            for(int n=0; n<9; n++){
                if(board[m][n] == '.'){
                    for(int p =0; p<9; p++){
                        board[m][n] = '1'+p;
                        if(isValid(m, n, board) && solveSudoku(board)){
                            return true;
                        }
                        board[m][n] = '.';
                    
                    }

                    return false;
                
                }
            
            }
        }
        
        return true;
    }
    
    
    bool isValid(int i, int j,  vector<vector<char>> &board){
        for(int m =0; m<9; m++){
            if(board[i][m] == board[i][j] && j!= m)
                return false;
        
        }
        
        
        for(int n =0; n<9; n++){
            if(board[n][j] == board[i][j] && i!=n)
                return false;
        
        }
        
        
        
        int rowMod = i/3;
        int colMod = j/3;
        
        
        for(int x=0; x<3; x++){
            for(int y = 0; y<3; y++){
                if(board[rowMod*3+x][colMod*3+y] == board[i][j] && rowMod*3+x!=i && colMod*3+y!=j)
                    return false;
                
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

