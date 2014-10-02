//
//  main.cpp
//  Triangle
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


//class Solution {
//public:
//    int minimumTotal(vector<vector<int> > &triangle) {
//        if (triangle.size() == 0) {
//            return 0;
//        }
//        
//        vector<vector<int>> f(triangle.size(), vector<int> (triangle.size()));
//        f[0][0] = triangle[0][0];
//        for (int i = 1; i < f.size(); i++) {
//            for (int j = 0; j <= i; j++) {
//                if (j == 0) {
//                    f[i][j] = f[i - 1][j] + triangle[i][j];
//                } else if(j == i){
//                    f[i][j] = f[i - 1][j - 1] + triangle[i][j];
//                } else {
//                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
//                }
//            }
//            
//        }
//        
//        
//        int result = INT_MAX;
//        for (int i = 0; i < triangle.size(); i++) {
//            if (f[triangle.size() - 1][i] < result) {
//                result = f[triangle.size() - 1][i];
//            }
//        }
//        
//        return result;
//    }
//};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        
        int result = INT_MAX;
        vector<int> f (triangle.size(), 0);
        f[0] = triangle[0][0];
        int row = (int)triangle.size();
        int i = 1;
        while (i < row) {
            for (int j = i; j >= 0; j--) {
                if (j == 0) {
                    f[j] = f[j] + triangle[i][j];

                } else if (j == i) {
                    f[j] = f[j - 1] + triangle[i][j];

                } else {
                    f[j] = min(f[j], f[j - 1]) + triangle[i][j];

                }
            }
            
            i++;
        }
        for (int i = 0; i < row; i++) {
            result = min(result, f[i]);
        }
        
        return result;
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<vector<int>> triangle = {{2}, {3, 4}, {6,5,7}, {4,1,8,3}};
//    vector<vector<int>> triangle = {{-10}};
    Solution s;
    cout <<  s.minimumTotal(triangle) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

