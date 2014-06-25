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
        string first = word.substr(0, 1);
//        vector<vector<bool>> visited = {(int)board.size(), {(int)board[0].size()}, false};
        const int row= (int)board.size();
        const int col = (int)board[0].size();
        
        vector<vector<bool>> visited (row, vector<bool>(col, false));
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
         
                if(board[i][j] == *first.c_str()){
                   
                   if( dfs(word, board, 0, i, j, visited))
                       return true;
                
                }
                    
            }
        }
        return false;
    }
    
    
    bool dfs(string &str, vector<vector<char>> &board, int position, int i, int j, vector<vector<bool>> &visited){
//         if(position > str.length()-1) return false;
        int row =(int)board.size()-1;
        int col =(int)board[0].size()-1;
        
        if(i<0 || j<0 || i>row || j > col)
            return false;
        
        
        if(position == str.length()-1){
            if(visited[i][j] ==false && isExist(str.substr(position, 1), board, i, j)){
                visited[i][j] = true;
                return true;
            }else
                return false;
        }
        
        if(visited[i][j] == true)
            return false;
        
        
        if(isExist(str.substr(position, 1), board, i, j)){
            
            visited[i][j] = true;
            
            if( dfs(str, board, position +1, i-1, j, visited) || dfs(str, board, position +1, i+1, j, visited) || dfs(str, board, position+1, i, j-1, visited) || dfs(str, board, position+1, i, j+1, visited))
                return true;
        
        }
        
        visited[i][j] =false;
           return false;
    }
    
    
    bool isExist(string str, vector<vector<char>> &board, int i, int j){
     
        
        if(i >=0 && j>=0 && i<board.size() && j<board[0].size()){
            if(board[i][j] == *str.c_str())
                return true;
            
        }
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    
    Solution s;
//    vector<vector<char>> board = {{'F','Y','C','E','N','R','D'}, {'K','L','N','F','I','N','U'}, {'A','A','A','R','A','H','R'}, {'N','D','K','L','P','N','E'}, {'A','L','A','N','S','A','P'}, {'O','O','G','O','T','P','N'}, {'H','P', 'O','L','A','N','O'}};

    
//    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    
    vector<vector<char>> board = {{'C','A','A'},{'A','A','A'}, {'B','C','D'}};
    string word = "AAB";
    cout << s.exist(board, word) << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}

