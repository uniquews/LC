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

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // vector<int> eachLine;
        vector<vector<int>> result;
        
        if(numRows==0) return result;
        // if(numRows==1){
        //     eachLine.push_back(1);
        //     result.push_bakc(eachLine);
        // }
        
        for(int i=1; i<=numRows; i++){
            vector<int> newLine;
            if(i==1){
                newLine.push_back(1);
                result.push_back(newLine);
            }else{
                vector<int> lastLine;
                lastLine.push_back(0);
                for(int j=0; j<result.back().size();j++){
                    lastLine.push_back(result.back()[j]);
                }
                lastLine.push_back(0);
                
                
                for(int m=0; m<lastLine.size()-1; m++){
                    int temp = lastLine[m]+lastLine[m+1];
                    newLine.push_back(temp);
                }
                result.push_back(newLine);
            }
            
            
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{



    return 0;
}

