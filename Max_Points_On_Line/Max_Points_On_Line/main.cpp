//
//  main.cpp
//  Max_Points_On_Line
//
//  Created by Shuai Wang on 7/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float, int> eachKey;
        int maxSame = 0;
        
        for (int i = 0; i < points.size(); i++) {
            eachKey.clear();
            eachKey[INT_MIN] = 0;
            int duplicate = 1;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                } else if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                } else {
                    if (points[i].y == points[j].y) {
                        eachKey[0]++;
                    } else {
                        if (points[i].x == points[j].x) {
                            eachKey[INT_MAX]++;
                        } else {
                            float key = (float)((points[i].x - points[j].x) / (float)(points[i].y - points[j].y));
                            eachKey[key]++;
                        }
                    }
                }
                
            }
            
            unordered_map<float, int> :: iterator it = eachKey.begin();
            for (; it != eachKey.end(); it++) {
                if (it->second + duplicate > maxSame) {
                    maxSame = it->second + duplicate;
                }
            }
            
        }
        
        return maxSame;
    }
};



int main(int argc, const char * argv[])
{

//    Point a (84,250);
//    Point b (0,0);
//    Point c (1,0);
//    Point d (0,-70);
//    Point e (0,-70);
//    Point f (1,-1);
//    Point g (21,10);
//    Point h (42,90);
//    Point i (-42,-230);
    
//    Point a (1,1);
//    Point b (0,0);
//    Point c (2,2);
//    Point d (2,3);
//    Point e (4,10);
//    Point f (1,1);
    
    Point a (0,0);
    
    vector<Point> v = {a};
    
    
    Solution su;
    cout << su.maxPoints(v);
    return 0;
}

