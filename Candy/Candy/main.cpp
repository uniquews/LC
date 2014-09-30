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
        
        vector<int> eachPerson(ratings.size());
        for (int i = 0; i <ratings.size(); i++) {
            if (i == 0) {
                eachPerson[i] = 1;
            } else {
                if (ratings[i] <= ratings[i - 1]) {
                    eachPerson[i] = 1;
                } else if (ratings[i] > ratings[i - 1]) {
                    eachPerson[i] = eachPerson[i - 1] + 1;
                }
            }
            
        }
        
        
        for (int i = (int)ratings.size() - 1, candy = 1; i >= 0; i--) {
            if (i == ratings.size() - 1) {
                eachPerson[i] = max(candy, eachPerson[i]);
                candy = eachPerson[i];
            } else {
                if (ratings[i] > ratings[i + 1]) {
                    eachPerson[i] = max(candy + 1, eachPerson[i]);
                    candy = eachPerson[i];
                } else if (ratings[i] <= ratings[i + 1]) {
                    eachPerson[i] = max(1, eachPerson[i]);
                    candy = eachPerson[i];
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < eachPerson.size(); i++) {
            result += eachPerson[i];
        }
        
        return result;
    }
};



int main(int argc, const char * argv[])
{

    vector<int> ratings = {2,2,1};
    Solution su;
    cout << su.candy(ratings) << endl;
    return 0;
}

