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
#include <vector>

using namespace std;


//class Solution {
//public:
//    int ladderLength(string start, string end, unordered_set<string> &dict) {
//        if (start.size() == 0 || end.size() == 0) {
//            return 0;
//        }
//        
//        queue<string> strList;
//        strList.push(start);
//        int len = 0;
//        
//        while (strList.size() != 0) {
//            int count = (int)strList.size();
//            for (int i = 0; i < count; i++) {
//                string cur = strList.front();
//                strList.pop();
//                
//                for (char tri = 'a'; tri <= 'z'; tri++) {
//                    for (int j = 0; j < cur.size(); j++) {
//                        string tmp = cur;
//                        if (tri == tmp[j]) {
//                            continue;
//                        }
//                        
//                        tmp[j] = tri;
//                        if (cur == end) {
//                            return len + 1;
//                        }
//                      
//                        if (dict.find(tmp) != dict.end()) {
//                            strList.push(tmp);
//                            dict.erase(tmp);
//                        }
//                    }
//                }
//                
//            }
//            
//            len++;
//        }
//        
//        return 0;
//        
//    }
//};

//class Solution {
//public:
//    int ladderLength(string start, string end, unordered_set<string> &dict) {
//        if (start.size() == 0 && end.size() == 0) {
//            return 0;
//        }
//        
//        queue<string> q;
//        int len = 1;
//        q.push(start);
//        dict.erase(start);
//        
//        while (q.size() != 0) {
//            
//            int n = (int)q.size();
//          
//            for (int i = 0; i < n; i++) {
//                string cur = q.front();
//                q.pop();
//                
//                for (int j = 0; j < cur.size(); j++) {
//                    for (char tri = 'a'; tri <= 'z'; tri++) {
//                        if (cur[j] == tri) {
//                            continue;
//                        }
//                        
//                        string tmp = cur;
//                        tmp[j] = tri;
//                        
//                        if (tmp == end) {
//                            return len + 1;
//                        }
//                        
//                        if (dict.find(tmp) != dict.end()) {
//                            q.push(tmp);
//                            dict.erase(tmp);
//                        }
//                        
//                    }
//                }
//                
//            }
//            
//            len++;
//        }
//        
//        return 0;
//        
//    }
//};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> wordsList;
        int level = 1;
        wordsList.push(start);
      
        
        while (wordsList.size() != 0) {
            int eachLevelSize = (int)wordsList.size();
            int s = 0;
            while (s < eachLevelSize) {
                string cur = wordsList.front();
                string origin = cur;
                wordsList.pop();
                for (int i = 0; i < cur.size(); i++) {
                    for (char tri = 'a'; tri <= 'z'; tri++) {
                        cur[i] = tri;
                        if (cur == origin) {
                            continue;
                        }
                        
                        if (cur == end) {
                            level++;
                            return level;
                        }
                        
                        if (dict.find(cur) != dict.end()) {
                            wordsList.push(cur);
                            dict.erase(cur);
                        }
                        cur = origin;
                    }
                }
                s++;
            }
            level++;

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
    
    
//    string start = "hot";
//    string end = "dog";
//    unordered_set<string> dict = {"hot","dog","dot"};
    
    string start = "a";
    string end = "c";
    unordered_set<string> dict = {"a","b","c"};

    
    Solution su;
    cout << su.ladderLength(start, end, dict) << endl;
    return 0;
}

