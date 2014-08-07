//
//  main.cpp
//  Spiral Matrix
//
//  Created by Shuai Wang on 6/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;



//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int> > &matrix) {
//        
//        int m = (int)matrix.size();  // row
//        if(m==0)return vector<int>();
//        int n = (int)matrix[0].size(); //column
//        if(n==0)return vector<int>();
//        
//        vector<int> result(m*n, 0);
//        int layer;
//        int index=0;
//        
//        for(layer=min(m,n); layer>1; layer-=2){
//            int offset = (min(m,n) - layer)/2;
//            
//            // left to right
//            for(int i=offset; i<n-offset-1; i++){
//                result[index++] = matrix[offset][i];
//            }
//            
//            //top to bottom
//            for(int i=offset; i<m-offset-1; i++){
//                result[index++]= matrix[i][n-offset-1];
//            }
//            
//            //right to left
//            for(int i=n-offset-1; i>offset; i--){
//                result[index++]=matrix[m-offset-1][i];
//            }
//            
//            //bottom to top
//            for(int i=m-offset-1; i>offset; i--){
//                result[index++] = matrix[i][offset];
//            }
//        }
//        
//        
//        if(layer==1){
//            
//            if(m>n){
//                for(int i=n/2; i<m-n/2; i++){
//                    result[index++]=matrix[i][n/2];
//                }
//            }else{
//                for(int i=m/2; i<n-m/2; i++){
//                    result[index++] = matrix[m/2][i];
//                }
//            }
//        }
//        
//        return result;
//        
//    }
//    
//    
//};


template <>
struct std::hash<std::pair<int, int> > {
public:
    size_t operator()(std::pair<int, int> x) const throw() {
        size_t h = x.first * 100 + x.second;//something with x
        return h;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        
        vector<int> result;
        
        
        if(row == 0 || column == 0){
            return result;
        }
        
        int startRow = 0;
        int endRow = row - 1;
        int startColumn = 0;
        int endColumn = column - 1;
        
        while(startRow <= endRow && startColumn <= endColumn){
            int tempRow = startRow;
            if(startColumn == endColumn && startRow == endRow){
                result.push_back(matrix[startRow][startColumn]);
            }else if(startColumn != endColumn && startRow == endRow){
                for(int i = startColumn; i <= endColumn; i++){
                    result.push_back(matrix[startRow][i]);
                }
            }else if(startColumn == endColumn && startRow != endRow){
                for(int i = startRow; i <= endRow; i++){
                    result.push_back(matrix[i][startColumn]);
                }
            }else{
                for(int i = startColumn; i < endColumn; i++){
                    result.push_back(matrix[tempRow][i]);
                }
                
                int tempColumn = endColumn;
                for(int i = startRow; i < endRow; i++){
                    result.push_back(matrix[i][tempColumn]);
                }
                
                tempRow = endRow;
                for(int i = endColumn; i > startColumn; i--){
                    result.push_back(matrix[tempRow][i]);
                }
                
                tempColumn = startColumn;
                for(int i = endRow; i > startRow; i--){
                    result.push_back(matrix[i][tempColumn]);
                }
            }
            
          startRow = startRow + 1;
            endRow = endRow - 1;
            startColumn = startColumn + 1;
            endColumn = endColumn - 1;
        }
        
        return result;
        
    }
    
};



int main(int argc, const char * argv[])
{

// Test Case:
//    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16},{17, 18, 19, 20}};
//    vector<vector<int>> matrix = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};
//    vector<vector<int>> matrix = {{1,2,3,4,5,6}, {7,8,9,10,11,12}, {13,14,15,16,17,18}, {19,20,21,22,23,24},{25,26,27,28,29,30}};
//    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15}};
//    vector<vector<int>> matrix = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
//    vector<vector<int>> matrix = {{}};
    
//    vector<vector<int>> matrix = {{2,3,4}, {5,6,7},{8,9,10}, {11,12,13}};
    
//    vector<vector<int>> matrix ={{1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}};
//    vector<vector<int>> matrix = {{1,11}, {2,12}, {3,13}, {4, 14}, {5,15}, {6, 16}, {7, 17}, {8, 18}, {9, 19},{10,20}};
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36, 37, 38, 39, 40}, {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}, {51, 52, 53, 54, 55, 56, 57, 58, 59, 60}, {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},{71, 72, 73, 74, 75, 76, 77, 78, 79, 80}, {81, 82, 83, 84, 85, 86, 87, 88, 89, 90}, {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};
    
    Solution su;
    vector<int> result = su.spiralOrder(matrix);
    vector<int> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
    }
 
    return 0;
}

