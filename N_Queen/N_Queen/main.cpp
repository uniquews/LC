//
//  main.cpp
//  N_Queen
//
//  Created by Shuai Wang on 6/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string> > solveNQueens(int n) {
        vector<int> board (n, -2);
        dfs(board, 0, n);
    
        
        return result;
    }
    
    void printResult(vector<int> &board, int n){
        vector<string> eachResult;
        for(int i=0; i<n; i++){
            string str(n, '.');
            str[board[i]]='Q';
            eachResult.push_back(str);
        }
        result.push_back(eachResult);
    
    }
    
    
    void dfs(vector<int> &board, int curRow, int n){
        if(curRow == n){
            printResult(board, n);
        }else{
            for(int i=0; i<n; i++){
                board[curRow] = i;
                if(isValid(board, curRow)){
                    dfs(board, curRow+1, n);
                }
            }
        
        }
        
     
    
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

    // insert code here...
    Solution s;
    vector<vector<string>> result = s.solveNQueens(1);
    vector<vector<string>> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<string> ::iterator it2 = it->begin();
        for(; it2!=it->end(); it2++){
            cout << *it2 << " ";
        }
    
        cout << endl;
    }
    
    
    
    
//    std::cout << "Hello, World!\n";
    return 0;
}

