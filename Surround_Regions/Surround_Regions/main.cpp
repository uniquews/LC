//
//  main.cpp
//  Surround_Regions
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) {
            return;
        }
        
        int row = (int)board.size();
        int column = (int)board[0].size();
        
        vector<vector<int>> change;
        
        for (int i = 0; i < column; i++) {
            if (board[0][i] == 'O') {
                vector<int> each = {0, i};
                change.push_back(each);
                board[0][i] = 'Y';
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (board[i][column - 1] == 'O') {
                vector<int> each = {i, column - 1};
                change.push_back(each);
                board[i][column - 1] = 'Y';
            }
        }
        
        for (int i = 0; i < column; i++) {
            if (board[row - 1][i] == 'O') {
                vector<int> each = {row - 1, i};
                change.push_back(each);
                board[row - 1][i] = 'Y';
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                vector<int> each = {i, 0};
                change.push_back(each);
                board[i][0] = 'Y';
            }
        }
        
        int num = 0;
        
        while (num < change.size()) {
            vector<int> cur = change[num];
            int tmpR = cur[0];
            int tmpC = cur[1];
            if (tmpR - 1 >= 0 && board[tmpR - 1][tmpC] == 'O') {
                vector<int> each = {tmpR - 1, tmpC};
                change.push_back(each);
                board[tmpR - 1][tmpC] = 'Y';
            }
            
            if (tmpR + 1 < row && board[tmpR + 1][tmpC] == 'O') {
                vector<int> each = {tmpR + 1, tmpC};
                change.push_back(each);
                board[tmpR + 1][tmpC] = 'Y';
            }
            
            if (tmpC + 1 < column && board[tmpR][tmpC + 1] == 'O') {
                vector<int> each = {tmpR, tmpC + 1};
                change.push_back(each);
                board[tmpR][tmpC + 1] = 'Y';
            }
            
            if (tmpC - 1 >= 0 && board[tmpR][tmpC - 1] == 'O') {
                vector<int> each = {tmpR, tmpC - 1};
                change.push_back(each);
                board[tmpR][tmpC - 1] = 'Y';
            }
            
            num++;
            
        }
        
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                
            }
        }
        
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
                
            }
        }
        
        return;
        
    }
};


//class Solution {
//public:
//    void solve(vector<vector<char>> &board) {
//        if (board.size() == 0) {
//            return;
//        }
//        stack<int> *xIndex = new stack<int> ();
//        stack<int> *yIndex = new stack<int> ();
//        
//        int row = (int)board.size();
//        int column = (int)board[0].size();
//        
//        for (int i = 0; i < column; i++) {
//            if (board[0][i] == 'O') {
//                xIndex->push(0);
//                yIndex->push(i);
//                iterative(board, xIndex, yIndex);
//          }
//        }
//        
//        for (int i = 0; i < row; i++) {
//            if (board[i][0] == 'O') {
//                xIndex->push(i);
//                yIndex->push(0);
//                iterative(board, xIndex, yIndex);
//            }
//        }
//        
//        
//        
//        for (int i = 0; i < column; i++) {
//            if (board[row - 1][i] == 'O') {
//                xIndex->push(row - 1);
//                yIndex->push(i);
//                iterative(board, xIndex, yIndex);
//            }
//        }
//        
//        for (int i = 0; i < row; i++) {
//            if (board[i][column - 1] == 'O') {
//                xIndex->push(i);
//                yIndex->push(column - 1);
//                iterative(board, xIndex, yIndex);
//            }
//        }
//        
//        
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++) {
//                if (board[i][j] == 'O') {
//                    board[i][j] = 'X';
//                }
//                
//                if (board[i][j] == 'Y') {
//                    board[i][j] = 'O';
//                }
//            }
//        
//        }
//        
//        delete xIndex;
//        delete yIndex;
//        xIndex = nullptr;
//        yIndex = nullptr;
//        
//        return;
//        
//        
//    }
//    
//    
//    
//    void iterative(vector<vector<char>> &board, stack<int> *xIndex, stack<int> *yIndex) {
//        int row = (int)board.size();
//        int column = (int)board[0].size();
//        
//        while (xIndex->size() != 0) {
//            int index1 = xIndex->top();
//            int index2 = yIndex->top();
//            board[index1][index2] = 'Y';
//            
//            
//            xIndex->pop();
//            yIndex->pop();
//            
//            if (index1 > 0 && board[index1 - 1][index2] == 'O') {
//                xIndex->push(index1 - 1);
//                yIndex->push(index2);
//            }
//            
//            
//            if (index1 < row - 1 && board[index1 + 1][index2] == 'O') {
//                xIndex->push(index1 + 1);
//                yIndex->push(index2);
//            }
//            
//            if (index2 > 0 && board[index1][index2 - 1] == 'O') {
//                xIndex->push(index1);
//                yIndex->push(index2 - 1);
//            }
//            
//            
//            if (index2 < column - 1 && board[index1][index2 + 1] == 'O') {
//                xIndex->push(index1);
//                yIndex->push(index2 + 1);
//            }
//        }
//        
//    }
//    
//    
//};

//class Solution {
//public:
//    void solve(vector<vector<char>> &board) {
//        if (board.size() == 0) {
//            return;
//        }
//        
//        int row = board.size();
//        int column = board[0].size();
//        
//        vector<int> xIndex;
//        vector<int> yIndex;
//        for (int i = 0; i < column; i++) {
//            if (board[0][i] == 'O') {
//                xIndex.push_back(0);
//                yIndex.push_back(i);
//            }
//        }
//        
//        for (int i = 0; i < row; i++) {
//            if (board[i][0] == 'O') {
//                xIndex.push_back(i);
//                yIndex.push_back(0);
//            }
//        }
//        
//        for (int i = 0; i < column; i++) {
//            if (board[row - 1][i] == 'O') {
//                xIndex.push_back(row - 1);
//                yIndex.push_back(i);
//            }
//        }
//        
//        for (int i = 0; i < row; i++) {
//            if (board[i][column - 1] == 'O') {
//                xIndex.push_back(i);
//                yIndex.push_back(column - 1);
//            }
//        }
//        
//        int k = 0;
//        while (k < xIndex.size()) {
//            int x = xIndex[k];
//            int y = yIndex[k];
//            
//            board[x][y] = 'Y';
//            
//            if (x > 0 && board[x - 1][y] == 'O') {
//                xIndex.push_back(x - 1);
//                yIndex.push_back(y);
//            }
//            
//            if (x < row - 1 && board[x + 1][y] == 'O') {
//                xIndex.push_back(x + 1);
//                yIndex.push_back(y);
//            }
//            
//            if (y > 0 && board[x][y - 1] == 'O') {
//                xIndex.push_back(x);
//                yIndex.push_back(y - 1);
//            }
//            
//            if (y < column - 1 && board[x][y + 1] == 'O') {
//                xIndex.push_back(x);
//                yIndex.push_back(y + 1);
//            }
//            
//            k++;
//        }
//        
//        
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < column; j++) {
//                if (board[i][j] == 'O') {
//                    board[i][j] = 'X';
//                }
//                
//                if (board[i][j] == 'Y') {
//                    board[i][j] = 'O';
//                }
//            }
//        }
//        
//        return;
//        
//    }
//    
//};
int main(int argc, const char * argv[])
{
//
//    vector<vector<char>> board = {{'O','O','O','O','X','X'}, {'O','O','O','O','O','O'}, {'O','X','O','X','O','O'}, {'O','X','O','O','X','O'}, {'O','X','O','X','O','O'}, {'O','X','O','O','O','O'}};
//    vector<vector<char>> board = {{'X','O','X'}, {'O','X','O'}, {'X','O','X'}};
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution su;
    su.solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

