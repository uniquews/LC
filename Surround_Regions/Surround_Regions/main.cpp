//
//  main.cpp
//  Surround_Regions
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    
    void solve(vector<vector<char>> &board) {
        
        vector<int> xIndex;
        vector<int> yIndex;
        int row = (int)board.size();
        if(row == 0) return;
        int column  = (int)board[0].size();
        
        //        search(row, column, board);
        
        //The first row
        for(int i=0; i<column; i++){
            if(board[0][i]=='O'){
                xIndex.push_back(0);
                yIndex.push_back(i);
            }
            
            
            
        }
        
        for(int i=0; i<row; i++){
            if(board[i][column-1] == 'O'){
                xIndex.push_back(i);
                yIndex.push_back(column-1);
            }
            
        }
        
        for(int i=0; i<column; i++){
            if(board[row-1][i] == 'O'){
                xIndex.push_back(row-1);
                yIndex.push_back(i);
            }
            
        }
        
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                xIndex.push_back(i);
                yIndex.push_back(0);
            }
            
            
        }
        
        int k = 0;
        while(k<xIndex.size()){
            int x = xIndex[k];
            int y = yIndex[k];
            
            board[x][y]='Y';
            
            if(x>0 && board[x-1][y] == 'O') {
                xIndex.push_back(x-1);
                yIndex.push_back(y);
            }
            
            if(y>0 && board[x][y-1] == 'O'){
                xIndex.push_back(x);
                yIndex.push_back(y-1);
            }
            
            if(x<row-1 && board[x+1][y] == 'O'){
                xIndex.push_back(x+1);
                yIndex.push_back(y);
            }
            
            if(y<row-1 && board[x][y+1] == 'O'){
                xIndex.push_back(x);
                yIndex.push_back(y+1);
            }
            
            k++;
            
        }
        
        for(int i= 0; i< row; i++){
            for(int j = 0; j<column; j++){
                if(board[i][j] == 'O') board[i][j] ='X';
                if(board[i][j] == 'Y') board[i][j] = 'O';
            }
            
        }
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

