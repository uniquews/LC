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


class Solution {
    
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float, int> eachKey;
        int maxSame = 0;
        
        for(int i=0; i<points.size(); i++){
            int duplicate = 1;
            eachKey.clear();
            eachKey[INT_MIN] = 0; //[0,0][0,0]  or [1,1] [1,1] [1,1]... only has duplicate points
            for(int j =0; j<points.size(); j++){
                if(i == j) continue;
                
                //count duplicate
                if(points[j].x == points[i].x && points[j].y == points[i].y){
                    duplicate++;
                    continue;
                }
                
                //for line is vertical to the x axis
                
            // Dividing two integer to produce a float result: http://stackoverflow.com/questions/12447325/dividing-two-integers-to-produce-a-float-result
                float key = (points[j].x - points[i].x) == 0 ?INT_MAX :(float) (points[j].y - points[i].y) / (float)(points[j].x - points[i].x);                eachKey[key]++;
            }
            
            unordered_map<float, int>::iterator it = eachKey.begin();
            for(; it!=eachKey.end(); it++){
                if(it->second + duplicate > maxSame)
                    maxSame = it->second + duplicate;
            }
            
        }
        
        return maxSame;
        
        
    }
 
};



int main(int argc, const char * argv[])
{

    Point a (84,250);
    Point b (0,0);
    Point c (1,0);
    Point d (0,-70);
    Point e (0,-70);
    Point f (1,-1);
    Point g (21,10);
    Point h (42,90);
    Point i (-42,-230);
    
    vector<Point> v = {a,b,c,d,e,f,g,h,i};
    
    
    Solution su;
    cout << su.maxPoints(v);
    return 0;
}

