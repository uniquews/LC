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

//class Solution {
//public:
//    bool exist(vector<vector<char> > &board, string word) {
//        string firstLetter = word.substr(0,1);
//        
//        int row = board.size();
//        int column = board[0].size();
//        
//        vector<vector<bool>> visited (row, vector<bool> (column, false));
//        
//        for(int i=0; i<row; i++){
//            for(int j=0; j<column; j++){
//                if(board[i][j] == *firstLetter.c_str()){
//                    if(dfs(board, word, 0, i, j, visited))
//                        return true;
//                }
//            }
//        }
//        
//        return false;
//    }
//    
//    
//    bool dfs(vector<vector<char>> &board, string word, int position, int i, int j, vector<vector<bool>> &visited){
//        int row = board.size()-1;
//        int column = board[0].size()-1;
//        if(i <0 || j<0 || i>row || j> column)
//            return false;
//        
//        if(position == word.size()-1){
//            if(visited[i][j] == false && word[position] == board[i][j]){
//                visited[i][j];
//                return true;
//            }else
//                return false;
//        }else{
//            if(visited[i][j] == true)
//                return false;
//            else{
//                if(word[position] == board[i][j]){
//                    visited[i][j] = true;
//                    
//                    if(dfs(board, word, position+1, i-1, j, visited) || dfs(board, word, position+1, i+1, j, visited) ||
//                       dfs(board, word, position+1, i, j-1, visited) || dfs(board, word, position+1, i, j+1, visited))
//                        return true;
//                }
//                
//                visited[i][j] = false;
//                return false;
//            }
//        }
//    }
//};


class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        int column = board[0].size();
        
        vector<vector<bool>> visited;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
                
            }
        }
        
        return false;
        
    }
    
    
    bool dfs(vector<vector<char>> board, string word, int i, int j, int index, vector<vector<bool>> &visited) {
        int row = board.size();
        int column = board[0].size();
        
        if (i < 0 || j < 0 || i >= row || j >= column) {
            return false;
        }
        
        if (index == word.size() - 1) {
            if (word[index] == board[i][j] && visited[i][j] == false) {
                return true;
            } else {
                return false;
            }
        } else {
            if (word[index] == board[i][j] && visited[i][j] == false) {
                visited[i][j] = true;
                if (dfs(board, word, i + 1, j, index + 1, visited)
                    || dfs(board, word, i - 1, j, index + 1, visited)
                    || dfs(board, word, i, j + 1, index + 1, visited)
                    || dfs(board, word, i, j - 1, index + 1, visited)) {
                    return true;
                } else {
                    visited[i][j] = false;
                    return false;
                }
                
            } else {
                return false;
            }
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

