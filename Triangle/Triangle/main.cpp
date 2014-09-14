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
//        for(int i=triangle.size()-2; i>=0; i--){
//            for(int j=0; j<i+1; j++){
//                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
//            }
//        }
//        
//        return triangle[0][0];
//    }
//    
//};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        
        vector<vector<int>> f(triangle.size(), vector<int> (triangle.size()));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < f.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    f[i][j] = f[i - 1][j] + triangle[i][j];
                } else if(j == i){
                    f[i][j] = f[i - 1][j - 1] + triangle[i][j];
                } else {
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
                }
            }
            
        }
        
        
        int result = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) {
            if (f[triangle.size() - 1][i] < result) {
                result = f[triangle.size() - 1][i];
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<vector<int>> triangle = {{1}, {2, 3}};
//    vector<vector<int>> triangle = {{-10}};
    Solution s;
    cout <<  s.minimumTotal(triangle) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

