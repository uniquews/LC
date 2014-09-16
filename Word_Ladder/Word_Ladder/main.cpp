//
//  main.cpp
//  Word_Ladder
//
//  Created by Shuai Wang on 9/16/14.
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
        queue<string> curLevel;
        queue<string> nextLevel;
        unordered_set<string> visited;
        curLevel.push(start);
        int length = 1;
        
        while (curLevel.empty() == false) {
            length++;
            while (curLevel.empty() == false) {
                string current = curLevel.front();
                curLevel.pop();
                for (int i = 0; i < current.size(); i++) {
                    for (char tri = 'a'; tri <= 'z'; tri++) {
                        string tmp = current;
                        tmp[i] = tri;
                        
                        if (current[i] == tri) {
                            continue;
                        }
                        
                        if (tmp == end) {
                            return length;
                        }
                        
                        if (dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()) {
                            visited.insert(tmp);
                            nextLevel.push(tmp);
                        }
                    }
                }
                
            }
            
            if (nextLevel.empty() == false) {
                curLevel = nextLevel;
                while(!nextLevel.empty()){ //!!important
                    nextLevel.pop();
                }
            }
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[])
{

    string start = "hit";
    string end = "cog";
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    
    Solution su;
    cout << su.ladderLength(start, end, dict) << endl;
    return 0;
}

