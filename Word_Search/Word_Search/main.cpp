//
//  main.cpp
//  Word_Search
//
//  Created by Shuai Wang on 6/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) {
            return false;
        }
        
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0, visited)) {
                        return true;
                    }
                }
                
            }
            
        }
        
        
        return false;
    }
    
    
    bool dfs(vector<vector<char>> &board, int row, int column, string word, int index, vector<vector<bool>> &visited) {
        if (index == word.size()) {
            return true;
        }
        
        if (row < 0 || row >= board.size() || column < 0 || column >= board[row].size()) {
            return false;
        }
        
        if (visited[row][column] == true) {
            return false;
        }
        
        if (board[row][column] != word[index]) {
            return false;
        }
        
        visited[row][column] = true;
        
        if ( dfs(board, row + 1, column, word, index + 1, visited) || dfs(board, row, column + 1, word, index + 1, visited) ||
            dfs(board, row - 1, column, word, index + 1, visited) || dfs(board, row, column - 1, word, index + 1, visited))         {
            return true;
        } else {
            visited[row][column] = false;
            return false;
        }
        
        
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution s;
//    vector<vector<char>> board = {{'F','Y','C','E','N','R','D'}, {'K','L','N','F','I','N','U'}, {'A','A','A','R','A','H','R'}, {'N','D','K','L','P','N','E'}, {'A','L','A','N','S','A','P'}, {'O','O','G','O','T','P','N'}, {'H','P', 'O','L','A','N','O'}};

    
//    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    
//    vector<vector<char>> board = {{'C','A','A'},{'A','A','A'}, {'B','C','D'}};
    vector<vector<char>> board = {{'a'}};
    string word = "a";
    cout << s.exist(board, word) << endl;
    

    
    std::cout << "Hello, World!\n";
    return 0;
}

