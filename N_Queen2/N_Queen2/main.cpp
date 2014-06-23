//
//  main.cpp
//  N_Queen2
//
//  Created by Shuai Wang on 6/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int total=0;
        vector<int> board (n, -2);
        return dfs(board, 0, n, total);
        
    }
    
    
    
    int dfs(vector<int> &board, int curRow, int n, int &total){
        if(curRow == n){
            // printResult(board, n);
            total++;
        }else{
            for(int i=0; i<n; i++){
                board[curRow] = i;
                if(isValid(board, curRow)){
                    dfs(board, curRow+1, n, total);
                }
            }
            
        }
        
        return total;
        
    }
    
    bool isValid(vector<int> &board, int curRow){
        for(int i=0; i<curRow; i++){
            if(board[curRow] == board[i] || curRow - i== abs(board[i] - board[curRow]))
                return false;
        }
        return true;
    }
    
};

int main(int argc, const char * argv[])
{

     Solution s;
    cout <<     s.totalNQueens(1) << endl;
    return 0;
}

