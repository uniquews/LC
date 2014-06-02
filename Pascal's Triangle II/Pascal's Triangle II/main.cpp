//
//  main.cpp
//  Pascal's Triangle II
//
//  Created by Shuai Wang on 6/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> newLine;
        vector<int> lastLine;
        
        
        // if(rowIndex==0) return newLine;
        for(int i=0; i<=rowIndex; i++){
            newLine.clear();
            if(i==0){
                newLine.push_back(1);
                lastLine.push_back(1);
            }else{
                
                std::vector<int>::iterator it;
                it=lastLine.begin();
                lastLine.insert(it, 0);
                // for(int j=0; j<lastLine.size();j++){
                //      lastLine.push_back(lastLine[j]);
                // }
                lastLine.push_back(0);
                
                
                for(int m=0; m<lastLine.size()-1; m++){
                    int temp = lastLine[m]+lastLine[m+1];
                    newLine.push_back(temp);
                }
                
                // lastLine = newLine;
                
                //lastLine has its own value (0,1,0) before. If we use this way, then (1,1,0), which is wrong
                // for(int k=0; k<newLine.size(); k++)
                //     lastLine[k] = newLine[k];
                
            }
            
            
        }
        
        return lastLine;
    }
};

int main(int argc, const char * argv[])
{

    
    return 0;
}

