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
//        vector<vector<int>> f;
//        f.resize(triangle.size(), vector<int>(triangle.size(), 0));
//        f[0][0]= triangle[0][0];
//        return dp(triangle, f);
//        
//    }
//    
//    int dp(vector<vector<int>> &triangle, vector<vector<int>> &f){
//        int i =1;
//        for(; i<triangle.size(); i++){
//            int temp = (int) triangle[i].size();
//            for(int j = 0; j<temp; j++){
//                if(j == 0)
//                    f[i][j] = f[i-1][0]+triangle[i][j];
//                else if(j == (int)triangle[i].size()-1)
//                    f[i][j] = f[i-1][(int)triangle[i].size()-2] + triangle[i][j];
//                else
//                    f[i][j] = min(f[i-1][j], f[i-1][j-1])+triangle[i][j];
//            }
//        
//        }
//        
//        int smallest = INT_MAX;
//        int temp = (int) triangle[i-1].size();
//        for(int k = 0; k<temp; k++){
//            if(f[i-1][k] < smallest)
//                smallest = f[i-1][k];
//        
//        }
//        
//        return smallest;
//    
//    }
//};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<i+1; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    vector<vector<int>> triangle = {{-1}, {-2, -3}};
//    vector<vector<int>> triangle = {{-10}};
    Solution s;
    cout <<  s.minimumTotal(triangle) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

