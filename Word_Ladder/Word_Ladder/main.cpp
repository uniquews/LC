//
//  main.cpp
//  Word_Ladder
//
//  Created by Shuai Wang on 7/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> tempString;
        queue<string> nextLevel;
        tempString.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int length = 1;
        
        while(!tempString.empty()){
            length++;
            
            while(!tempString.empty()){
                string needToChange = tempString.front();
                tempString.pop();
                
                for(int i=0; i<needToChange.size(); i++){
                    for(char c='a'; c<='z'; c++){
                        string wait =needToChange;
                        wait[i] = c;
                        if(needToChange[i] == c) //!!important
                            continue;
                        if(wait == end){
                            
                            return length;
                        }
                        if(dict.find(wait)!=dict.end()&& visited.find(wait) == visited.end()){
                            
                            visited.insert(wait);
                            nextLevel.push(wait);
                        }
                        
                    }
                }
                
            }
            tempString = nextLevel;
            while(!nextLevel.empty()){ //!!important
                nextLevel.pop();
            }
            
        }
        
        
        
        return 0;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

