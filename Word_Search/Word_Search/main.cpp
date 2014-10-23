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
        if (word.size() == 0 || board.size() == 0) {
            return false;
        }
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, visited)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    
    bool dfs(vector<vector<char>> &board, string word, int index, int row, int column, vector<vector<bool>> &visited) {
        if (index == word.size()) {
            return true;
        } else if (row == board.size() || column == board[0].size() || row <  0 || column < 0) {
            return false;
        } else if (visited[row][column]) {
            return false;
        } else if (board[row][column] != word[index]) {
            return false;
        } else {
            visited[row][column] = true;
            if (dfs(board, word, index + 1, row + 1, column, visited) || dfs(board, word, index + 1, row - 1, column, visited) || dfs(board, word, index + 1, row, column + 1, visited) || dfs(board, word, index + 1, row, column - 1, visited)) {
                return true;
            }
            visited[row][column] = false;
        }
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution s;
//    vector<vector<char>> board = {{'F','Y','C','E','N','R','D'}, {'K','L','N','F','I','N','U'}, {'A','A','A','R','A','H','R'}, {'N','D','K','L','P','N','E'}, {'A','L','A','N','S','A','P'}, {'O','O','G','O','T','P','N'}, {'H','P', 'O','L','A','N','O'}};

    
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    
//    vector<vector<char>> board = {{'C','A','A'},{'A','A','A'}, {'B','C','D'}};
//    vector<vector<char>> board = {{'a'}};
    string word = "ABCB";
    cout << s.exist(board, word) << endl;
    

    
    std::cout << "Hello, World!\n";
    return 0;
}

