//
//  main.cpp
//  Search_A_2D_Matrix
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    bool searchMatrix(vector<vector<int> > &matrix, int target) {
//        int m = matrix.size();
//        int n = matrix.front().size();
//        
//        int first = 0;
//        int last = m * n;
//        
//        while(first < last){
//            int temp = (first+ last) /2;
//            int mid = matrix[temp / n][temp % n];
//            
//            if(target == mid)
//                return true;
//            if(target > mid){
//                first = ++temp;
//            }else
//                last = temp;
//        }
//        
//        return false;
//    }
//};


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int start = 0;
        int end = row * column - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid / column][mid % column] == target) {
                return true;
            } else if (matrix[mid / column][mid % column] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (matrix[start / column][start % column] == target) {
            return true;
        } else if (matrix[end / column][end % column] == target) {
            return true;
        } else {
            return false;
        }
        
        
    }
};

int main(int argc, const char * argv[])
{

    vector<vector<int>> matrix {{1}};
    Solution su;
    cout << su.searchMatrix(matrix, 2) << endl;
    return 0;
}

