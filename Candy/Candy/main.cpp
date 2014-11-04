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
        if (ratings.size() == 0) {
            return 0;
        }
        
        int result = 0;
        vector<int> child(ratings.size());
        child[0] = 1;
        for (int i = 0; i < child.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                child[i] = child[i - 1] + 1;
            } else {
                child[i] = 1;
            }
        }
        
        for (int i = (int)child.size() - 2;  i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                child[i] = max(child[i], child[i + 1] + 1);
            } else {
                child[i] = max(child[i], 1);
            }
        }
        
        for (int i = 0; i < child.size(); i++) {
            result += child[i];
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

//    vector<int> ratings = {2,2,1};
    vector<int> ratings = {1,2};
    
    Solution su;
    cout << su.candy(ratings) << endl;
    return 0;
}

