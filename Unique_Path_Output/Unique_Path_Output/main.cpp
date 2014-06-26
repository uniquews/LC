//
//  main.cpp
//  Unique_Path_Output
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    
    vector<vector<pair<int ,int>>> uniquePath(int m, int n){
        
        if(m == 0 || n==0)
            return vector<vector<pair<int, int>>>();
        vector<vector<pair <int, int>>> result;
        vector<pair<int, int>> eachPath;
        vector<vector<bool>> board;
        board.resize(m, vector<bool> (n, false));
        
        dfs(0, 0, board, result, eachPath);
        return result;
    
    }
    
    
    bool dfs(int row, int col, vector<vector<bool>> &board, vector<vector<pair <int,int>>> &result, vector<pair<int, int>> &eachPath){
        
        
        if(row< 0 || col <0 || row >(int)board.size()-1 || col > (int)board[0].size()-1)
            return false;
        
        if(board[row][col] == true)
            return false;

        if(row == (int)board.size()-1 && col == (int)board[0].size()-1){
            board[row][col] = true;
            eachPath.push_back(make_pair(row, col));
            result.push_back(eachPath);
            eachPath.pop_back();
            board[row][col] = false;
            return true;
        }
        
        
        
        board[row][col]=true;
        eachPath.push_back(make_pair(row, col));

        bool a= dfs(row+1, col, board, result, eachPath);
        

        bool b = dfs(row-1, col, board, result, eachPath);
       

        bool c=  dfs(row, col-1, board, result, eachPath);
        

        bool d= dfs(row, col+1, board, result, eachPath);
        board[row][col]=false;
        eachPath.pop_back();
    
        
        if(a||b||c||d){
        
            return true;
        }
        return false;
   
    }

};

int main(int argc, const char * argv[])
{

    Solution s;
    vector<vector<pair<int, int>>> result = s.uniquePath(2, 2);
    vector<vector<pair<int, int>>>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<pair<int, int>>:: iterator it2 = it->begin();
        for(; it2!=it->end(); it2++){
            cout << "[" << it2->first << "," << it2->second << "] ";
        
        }
        
        cout << endl;
    
    }

    

    return 0;
}

