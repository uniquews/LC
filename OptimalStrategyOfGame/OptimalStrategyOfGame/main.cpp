//
//  main.cpp
//  OptimalStrategyOfGame
//
//  Created by Shuai Wang on 8/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector> 

using namespace std;

class Solution {

public:
    
    int optimalStrategyGame (vector<int> pot) {
        
        if (pot.size() == 0) {
            return 0;
        }
        
        int num = (int)pot.size();
        vector<vector<int>> table (num, vector<int> (num, 0));
        
        //Initialize
        
        for (int i = 0; i < num; i++) {
            table[i][i] = pot[i];
        }
        
        for (int i = 0; i < num - 1; i++) {
            table[i][i + 1] = max(pot[i], pot[i + 1]);
        }
        
        // function
        for (int i = num - 1; i >= 0; i--) {
            for (int j = i; j < num; j++) {
                if (j - i < 2) {
                    continue;
                }
                
                int opt1 = table[i + 1][j - 1];
                int opt2 = table[i + 2][j];
                int opt3 = table[i][j - 2];
                
                int choice1 = min(opt1, opt2) + pot[i];
                int choice2 = min(opt1, opt3) + pot[j];
                
                table[i][j] = max(choice1, choice2);
            }
        }
        
        return table[0][num-1];
    }

};

int main(int argc, const char * argv[])
{

    //Test cases
    Solution su;
    
    vector<int> pot1 = {8, 15, 3, 7};
    vector<int> pot2 = {2, 2, 2, 2};
    vector<int> pot3 = {20, 30, 2, 2, 2, 10};
    vector<int> pot4 = {};
    vector<int> pot5 = {2,0,2};
    vector<int> pot6 = {0,2,0};
    vector<int> pot7 = {2,2,2};
    vector<int> pot8 = {1,2,3,4,5,6,7};
    vector<int> pot9 = {8,7,6,5,4,3,2,1};
    vector<int> pot10 = {7,6,5,4,3,2,1};
    vector<int> pot11 = {9,8,7,1,4,10,11};
//    cout << su.optimalStrategyGame(pot1) << endl;
//    cout << su.optimalStrategyGame(pot2) << endl;
//    cout << su.optimalStrategyGame(pot3) << endl;
//    cout << su.optimalStrategyGame(pot4) << endl;
//    cout << su.optimalStrategyGame(pot5) << endl;
//    cout << su.optimalStrategyGame(pot6) << endl;
//    cout << su.optimalStrategyGame(pot7) << endl;
//    cout << su.optimalStrategyGame(pot8) << endl;
//    cout << su.optimalStrategyGame(pot9) << endl;
//    cout << su.optimalStrategyGame(pot10) << endl;
      cout << su.optimalStrategyGame(pot11) << endl;
    return 0;
}

