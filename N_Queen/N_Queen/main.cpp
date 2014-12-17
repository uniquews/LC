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


//class Solution {
//public:
//    vector<vector<string> > solveNQueens(int n) {
//        if (n == 0) {
//            return vector<vector<string>> {};
//        }
//        
//        vector<vector<string>> result;
//        vector<int> board(n, INT_MAX);
//        dfs(board, 0, result);
//        return result;
//    }
//    
//    void dfs(vector<int> &board, int row, vector<vector<string>> &result) {
//        if (row == board.size()) {
//            getResult(board, result);
//            return;
//        }
//        
//        for (int i = 0; i < board.size(); i++) {
//            board[row] = i;
//            if (isValid(board, row, i)) {
//                dfs(board, row + 1, result);
//            }
//            board[row] = INT_MAX;
//        }
//        
//        return;
//    }
//    
//    bool isValid(vector<int> &board, int row, int column) {
//        for (int i = 0; i < board.size(); i++) {
//            if (i == row) {
//                continue;
//            } else {
//                if (board[i] == column) {
//                    return false;
//                }
//            }
//        }
//        
//        for (int i = 0; i < board.size(); i++) {
//            if (i == row) {
//                continue;
//            } else {
//                if (abs(i - row) == abs(board[i] - board[row])) {
//                    return false;
//                }
//            }
//        }
//        
//        return true;
//        
//    }
//    
//    void getResult (vector<int> &board, vector<vector<string>> &result) {
//        vector<string> eachResult;
//        for (int i = 0; i < board.size(); i++) {
//            string eachLine(board.size(), '.');
//            int column = board[i];
//            eachLine[column] = 'Q';
//            eachResult.push_back(eachLine);
//        }
//        
//        result.push_back(eachResult);
//        return;
//    }
//    
//};

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n == 0) {
            return vector<vector<string>> {};
        }
        
        vector<vector<string>> result;
        vector<int> board(n, -1);
        dfs(board, 0, result);
        return result;
    }
    
    void dfs(vector<int> &board, int row, vector<vector<string>> &result) {
        if (row == board.size()) {
            getResult(board, result);
            return;
        }
        
        for (int i = 0; i < board.size(); i++) {
            board[row] = i;
            if (isValid(board, row, i)) {
                dfs(board, row + 1, result);
            }
            board[row] = -1;
        }
        
        return;
    }
    
    bool isValid(vector<int> &board, int row, int column) {
        for (int i = 0; i < board.size(); i++) {
            if (i == row) {
                continue;
            } else {
                if (board[i] == column) {
                    return false;
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            if (i == row) {
                continue;
            } else {
                if (board[i] != -1) {
                    if (abs(i - row) == abs(board[i] - board[row])) {
                        return false;
                    }
                }
                
            }
        }
        
        return true;
        
    }
    
    void getResult (vector<int> &board, vector<vector<string>> &result) {
        vector<string> eachResult;
        for (int i = 0; i < board.size(); i++) {
            string eachLine(board.size(), '.');
            int column = board[i];
            eachLine[column] = 'Q';
            eachResult.push_back(eachLine);
        }
        
        result.push_back(eachResult);
        return;
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);
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

