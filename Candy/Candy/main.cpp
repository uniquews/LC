//
//  main.cpp
//  Candy
//
//  Created by Shuai Wang on 9/18/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> result(ratings.size());
        int sum = 0;
        
        for (int i = 0; i < ratings.size(); i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                result[i] = result[i - 1] + 1;
            } else {
                result[i] = 1;
            }
        }
        
        for (int i = ratings.size() - 1, candy = 1; i >= 0; i--) {
            if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1]) {
                result[i] = max(++candy, result[i]);
            } else {
                candy = 1;
            }
        }
        
        for (int i = 0; i < ratings.size(); i++) {
            sum += result[i];
        }
        
        return sum;
    }
};

int main(int argc, const char * argv[])
{

    vector<int> ratings = {2,1};
    Solution su;
    cout << su.candy(ratings) << endl;
    return 0;
}

