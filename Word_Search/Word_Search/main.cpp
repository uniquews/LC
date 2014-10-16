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
        if (board.size() == 0 || word.size() == 0) {
            return false;
        }
        
        int row = board.size();
        int column = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == word[0]) {
                    
                    if (dfs(board, i, j, word, 0, visited)) {
                        return true;
                    }
                    
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int index, vector<vector<bool>> &visited) {
        if (index == word.size()) {
            return true;
        }
        
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return false;
        }
        
        if (visited[i][j] == true) {
            return false;
        }
        
        if (board[i][j] != word[index]) {
            return false;
        }
        
        
        visited[i][j] = true;
        if (dfs(board, i + 1, j, word, index + 1, visited) || dfs(board, i, j + 1, word, index + 1, visited) || dfs(board, i - 1, j, word, index + 1, visited) || dfs(board, i, j - 1, word, index + 1, visited)) {
            return true;
        }
        
        visited[i][j] = false;
        
        return false;
        
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

