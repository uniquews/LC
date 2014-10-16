//
//  main.cpp
//  Pascal's Triangle
//
//  Created by Shuai Wang on 6/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int> > generate(int numRows) {
//        // vector<int> eachLine;
//        vector<vector<int>> result;
//        
//        if(numRows==0) return result;
//        // if(numRows==1){
//        //     eachLine.push_back(1);
//        //     result.push_bakc(eachLine);
//        // }
//        
//        for(int i=1; i<=numRows; i++){
//            vector<int> newLine;
//            if(i==1){
//                newLine.push_back(1);
//                result.push_back(newLine);
//            }else{
//                vector<int> lastLine;
//                lastLine.push_back(0);
//                for(int j=0; j<result.back().size();j++){
//                    lastLine.push_back(result.back()[j]);
//                }
//                lastLine.push_back(0);
//                
//                
//                for(int m=0; m<lastLine.size()-1; m++){
//                    int temp = lastLine[m]+lastLine[m+1];
//                    newLine.push_back(temp);
//                }
//                result.push_back(newLine);
//            }
//            
//            
//        }
//        
//        return result;
//    }
//};

//class Solution {
//public:
//    vector<vector<int> > generate(int numRows) {
//        vector<int> eachLevel;
//        vector<int> nextLevel;
//        vector<vector<int>> result;
//        int start = 1;
//        
//        while (start <= numRows) {
//            if (start == 1) {
//                eachLevel.push_back(1);
//                result.push_back(eachLevel);
//                start++;
//            } else {
//                nextLevel.push_back(0);
//                for (int i = 0 ; i < eachLevel.size(); i++) {
//                    nextLevel.push_back(eachLevel[i]);
//                }
//                nextLevel.push_back(0);
//                for (int i = 0; i < nextLevel.size() - 1; i++) {
//                    nextLevel[i] = nextLevel[i] + nextLevel[i + 1];
//                }
//                
//                nextLevel.pop_back();
//                eachLevel = nextLevel;
//                result.push_back(eachLevel);
//                nextLevel.clear();
//                start++;
//            }
//        }
//        
//        return result;
//    }
//};

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows == 0) {
            
            return vector<vector<int>> {};
        }
        vector<vector<int>> f(numRows);
        for (int i = 0; i < numRows; i++) {
            f[i] = vector<int>(i + 1);
        }
        
        f[0][0] = 1;
        int i = 1;
        while (i < numRows) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    f[i][j] = 1;
                } else if (j == i) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                }
                
            }
            
            i++;
            
        }
        
        return f;
    }
};
int main(int argc, const char * argv[])
{
    int numRow = 5;
    Solution su;
    vector<vector<int>> result = su.generate(numRow);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        
        cout << endl;
    }

    return 0;
}

