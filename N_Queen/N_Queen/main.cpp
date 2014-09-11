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



//class Solution {
//public:
//    vector<vector<string> > solveNQueens(int n) {
//        if (n == 0) {
//            return vector<vector<string>> ();
//        }
//        
//        vector<int> board(n, INT_MIN);
//        vector<vector<string>> result;
//        
//        dfs(board, 0, result);
//        
//        return result;
//    }
//    
//    void dfs(vector<int> &board, int row, vector<vector<string>> &result) {
//        if (row == board.size()) {
//            outputResult(board, result);
//            return;
//        }
//        
//        for (int i = 0; i < board.size(); i++) {
//            board[row] = i;
//            if (isValid(board, row, i)) {
//                dfs(board, row + 1, result);
//            }
//            
//            board[row] = INT_MIN;
//            
//        }
//    }
//    
//    bool isValid(vector<int> &board, int row, int column) {
//        for (int i = 0; i < board.size(); i++) {
//            if (i != row) {
//                if (board[i] == column) {
//                    return false;
//                }
//            }
//        }
//        
//        for (int i = 0; i < board.size(); i++) {
//            if (i != row) {
//                if (abs(row - i) == abs (board[row] - board[i])) {
//                    return false;
//                }
//            }
//        }
//        
//        return true;
//    }
//    
//    void outputResult(vector<int> &board, vector<vector<string>> &result) {
//        vector<string> eachResult;
//        for (int i = 0; i < board.size(); i++) {
//            string eachLine (board.size(), '.');
//            eachLine[board[i]] = 'Q';
//            eachResult.push_back(eachLine);
//        }
//        
//        result.push_back(eachResult);
//        
//        return;
//    }
//    
//    
//    
//};

//
//class Solution {
//public:
//    vector<vector<string> > solveNQueens(int n) {
//        
//        if (n == 0) {
//            return vector<vector<string>> {};
//        }
//        
//        vector<vector<string>> result;
//        vector<int> eachRow (n, INT_MIN);
//        dfs(n, result, eachRow, 0);
//        return result;
//    }
//    
//    void dfs(int n, vector<vector<string>> &result, vector<int> &eachRow, int cur) {
//        if (cur == n) {
//            output(n, result, eachRow);
//            return;
//        }
//        
//        for (int i = 0; i < n; i++) {
//            int preVal = eachRow[cur];
//            eachRow[cur] = i;
//            if (isValid(n, eachRow, cur, i) == true) {
//                dfs(n, result, eachRow, cur + 1);
//            }
//            eachRow[cur] = preVal;
//            
//            
//        }
//        
//        return;
//        
//    }
//    
//    
//    bool isValid(int n, vector<int> &eachRow, int cur, int column) {
//        
//        for (int i = 0; i < n; i++) {
//            if (i == cur) {
//                continue;
//            } else {
//                if (eachRow[i] == column) {
//                    return false;
//                }
//            }
//        }
//        
//        
//        
//        for (int i = 0; i < n; i++) {
//            if (i == cur) {
//                continue;
//            } else {
//                if (eachRow[i] != INT_MIN && abs(eachRow[i] - eachRow[cur]) == abs(i - cur)) {
//                    return false;
//                }
//            }
//        }
//        
//        return true;
//    }
//    
//    
//    void output(int n, vector<vector<string>> &result, vector<int> &eachRow) {
//        vector<string> eachSolution;
//        for (int i = 0; i < n; i++) {
//            string str (n, '.');
//            str[eachRow[i]] = 'Q';
//            eachSolution.push_back(str);
//            
//        }
//        
//        result.push_back(eachSolution);
//        
//        return;
//    }
//    
//    
//};

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

