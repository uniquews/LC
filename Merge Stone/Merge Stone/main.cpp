//
//  main.cpp
//  Merge Stone
//
//  Created by Shuai Wang on 10/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int mergeStone(vector<int> weight) {
        if (weight.size() == 0) {
            return 0;
        }
        
        int m = (int)weight.size();
        vector<vector<int>> f(m + 1, vector<int> (m + 1, INT_MAX));
        
        vector<int> sum (m + 1, 0);
        sum[0] = 0;
        sum[1] = weight[0];
        for (int i = 2; i <= m; i++) {
            sum[i] = sum[i - 1] + weight[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            f[i][i] = 0;
        }
        
        for (int len = 2; len <= m; len++) {
            for (int start = 1; start <= m - len + 1; start++) {
                int end = start + len - 1;
                for (int k = start; k < end; k++) {
                    f[start][end] = min(f[start][end], f[start][k] + f[k + 1][end] + sum[end] - sum[start - 1]);
                }
            
            }
        
        }
        
        return f[1][m];
    }
    

};

//int main(int argc, const char * argv[])
//{
//
//    vector<int> weight = {4, 1, 1, 4};
//    
//    Solution su;
//    cout << su.mergeStone(weight) <<endl;
//    return 0;
//}


int main()
{
    int num;
    cin >> num;
    
    vector<int> weight;
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        weight.push_back(tmp);
    }
    
    Solution su;
    return su.mergeStone(weight);
    
    
}

