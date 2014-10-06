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

//class Solution {
//public:
//    int ladderLength(string start, string end, unordered_set<string> &dict) {
//        queue<string> curLevel;
//        queue<string> nextLevel;
//        unordered_set<string> visited;
//        curLevel.push(start);
//        int length = 1;
//        
//        while (curLevel.empty() == false) {
//            length++;
//            while (curLevel.empty() == false) {
//                string current = curLevel.front();
//                curLevel.pop();
//                for (int i = 0; i < current.size(); i++) {
//                    for (char tri = 'a'; tri <= 'z'; tri++) {
//                        string tmp = current;
//                        tmp[i] = tri;
//                        
//                        if (current[i] == tri) {
//                            continue;
//                        }
//                        
//                        if (tmp == end) {
//                            return length;
//                        }
//                        
//                        if (dict.find(tmp) != dict.end() && visited.find(tmp) == visited.end()) {
//                            visited.insert(tmp);
//                            nextLevel.push(tmp);
//                        }
//                    }
//                }
//                
//            }
//            
//            if (nextLevel.empty() == false) {
//                curLevel = nextLevel;
//                while(!nextLevel.empty()){ //!!important
//                    nextLevel.pop();
//                }
//            }
//        }
//        
//        return 0;
//    }
//};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() == 0 || end.size() == 0) {
            return 0;
        }
        
        queue<string> strList;
        strList.push(start);
        int len = 0;
        
        while (strList.size() != 0) {
            int count = (int)strList.size();
            for (int i = 0; i < count; i++) {
                string cur = strList.front();
                strList.pop();
                
                for (char tri = 'a'; tri <= 'z'; tri++) {
                    for (int j = 0; j < cur.size(); j++) {
                        string tmp = cur;
                        if (tri == tmp[j]) {
                            continue;
                        }
                        
                        tmp[j] = tri;
                        if (cur == end) {
                            return len + 1;
                        }
                      
                        if (dict.find(tmp) != dict.end()) {
                            strList.push(tmp);
                            dict.erase(tmp);
                        }
                    }
                }
                
            }
            
            len++;
        }
        
        return 0;
        
    }
};

int main(int argc, const char * argv[])
{
//
//    string start = "hit";
//    string end = "cog";
//    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    
    
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict = {"hot","dog","dot"};
    
    Solution su;
    cout << su.ladderLength(start, end, dict) << endl;
    return 0;
}

