//
//  main.cpp
//  MergeSort
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//class Solution {
//public:
//    void solve(vector<vector<char>> &board) {
//        int row = board.size();
//        if(row == 0) return;
//        int column  = board[0].size();
//        
//        vector<int> xIndex;
//        vector<int> yIndex;
//        
//        for(int i=0; i<row; i++){
//            if(board[i][0] == 'O'){
//                xIndex.push_back(i);
//                yIndex.push_back(0);
//            }
//        }
//        
//        for(int i=0; i<row; i++){
//            if(board[i][column-1] = 'O'){
//                xIndex.push_back(i);
//                yIndex.push_back(column-1);
//            }
//        }
//        
//        for(int i=0; i<column; i++){
//            if(board[0][i] == 'O'){
//                xIndex.push_back(0);
//                yIndex.push_back(i);
//            }
//        }
//        
//        for(int i=0; i<column; i++){
//            if(board[row-1][i] == 'O'){
//                xIndex.push_back(row-1);
//                yIndex.push_back(i);
//            }
//        }
//        
//        
//        int k=0;
//        while(k<xIndex.size()){
//            int x = xIndex[k];
//            int y = yIndex[k];
//            
//            board[x][y] = 'Y';
//            
//            if(x>0 && board[x-1][y] == 'O'){
//                xIndex.push_back(x-1);
//                yIndex.push_back(y);
//            }
//            
//            if(x<row-1 && board[x+1][y] == 'O'){
//                xIndex.push_back(x+1);
//                yIndex.push_back(y);
//            }
//            
//            if(y>0 && board[x][y-1] == 'O'){
//                xIndex.push_back(x);
//                yIndex.push_back(y-1);
//            }
//            
//            if(y<column-1 && board[x][y+1] == 'O'){
//                xIndex.push_back(x);
//                yIndex.push_back(y+1);
//            }
//            
//            k++;
//        }
//        
//        
//        for(int i=0; i< row; i++){
//            for(int j = 0; j<column; j++){
//                if(board[i][j] == 'O') board[i][j] = 'X';
//                if(board[i][j] == 'Y') board[i][j] = 'O';
//            }
//        }
//        
//        return;
//    }
//    
//};


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> eachSet;
        sort(S.begin(), S.end());
        result.push_back(eachSet);
        unordered_map<int, bool> visited;
        dfs(result, eachSet, 0, visited, S);
        return result;
    }
    
    
    void dfs(vector<vector<int>> &result, vector<int> &eachSet, int position, unordered_map<int, bool> &visited, vector<int> &S) {
        for(int i = position; i < S.size(); i++){
            if(visited[S[i]] == false){
                eachSet.push_back(S[i]);
                visited[S[i]] = true;
                result.push_back(eachSet);
                if(i + 1 < S.size())
                    dfs(result, eachSet, i + 1, visited, S);
                eachSet.pop_back();
                visited[S[i]] = false;
            }
        }
    }
};


int main(int argc, const char * argv[])
{
    
//    Solution su;
//    vector<vector<char>> board= {{'X'}};
//    su.solve(board);
//    string start = "hot";
//    string end = "dog";
//    unordered_set<string> dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};
//    su.findLadders(start, end, dict);

//        int i;
//        char str[]="c3p  o...";
//        i=0;
//        while (isalnum(str[i])) i++;
//        printf ("The first %d characters are alphanumeric.\n",i);
//        return 0;

//    vector<int> S = {1,2};
//    Solution su;
//    su.subsets(S);
    
    unordered_map<int, int> needed;
    char temp = 'C';
    char temp2 = 'D';
    char temp3 = 'F';
    needed[temp] = 1;
    needed[temp2] = 2;
    needed[temp3] = 3;
    unordered_map<int, int> :: iterator it = needed.begin();
    for(; it != needed.end(); it++){
        cout << it->first << " - " << it->second << endl;
    }
    
    return 0;
}

