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



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) {
            return vector<int> {};
        }
        
        vector<int> result;
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        
        int startRow = 0;
        int endRow = row - 1;
        int startColumn = 0;
        int endColumn = column - 1;
        
        while (startRow <= endRow && startColumn <= endColumn) {
            if (startRow == endRow && startColumn == endColumn) {
                result.push_back(matrix[startRow][startColumn]);
                return result;
            } else if (startRow == endRow) {
                for (int i = startColumn; i <= endColumn; i++) {
                    result.push_back(matrix[startRow][i]);
                }
                return result;
            } else if (startColumn == endColumn) {
                for (int i = startRow; i <= endRow; i++) {
                    result.push_back(matrix[i][startColumn]);
                }
                return result;
            } else {
                
                // startRow
                for (int i = startColumn; i < endColumn; i++) {
                    result.push_back(matrix[startRow][i]);
                }
                
                //endColumn
                for (int i = startRow; i < endRow; i++) {
                    result.push_back(matrix[i][endColumn]);
                }
                
                // endRow
                for (int i = endColumn; i > startColumn; i--) {
                    result.push_back(matrix[endRow][i]);
                }
                
                //startColumn
                for (int i = endRow; i > startRow; i--) {
                    result.push_back(matrix[i][startColumn]);
                }
                
                startRow++;
                endRow--;
                startColumn++;
                endColumn--;
            }
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
//    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36, 37, 38, 39, 40}, {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}, {51, 52, 53, 54, 55, 56, 57, 58, 59, 60}, {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},{71, 72, 73, 74, 75, 76, 77, 78, 79, 80}, {81, 82, 83, 84, 85, 86, 87, 88, 89, 90}, {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};
    vector<vector<int>> matrix = {{2,3}};
    
    
    Solution su;
    vector<int> result = su.spiralOrder(matrix);
    vector<int> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
    }
 
    return 0;
}

