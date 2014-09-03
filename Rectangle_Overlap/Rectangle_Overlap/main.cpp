//
//  main.cpp
//  Rectangle_Overlap
//
//  Created by Shuai Wang on 9/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct Point
{
    int x, y;
};

class Solution {
public:
    
    bool doOverlap(Point l1, Point r1, Point l2, Point r2)
    {
        // If one rectangle is on left side of other
        if (l1.x > r2.x || l2.x > r1.x)
            return false;
        
        // If one rectangle is above other
        if (l1.y < r2.y || l2.y < r1.y)
            return false;
        
        return true;
    }
    

};

int main(int argc, const char * argv[])
{

    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    
    Solution su;
    if (su.doOverlap(l1, r1, l2, r2))
        printf("Rectangles Overlap");
    else
        printf("Rectangles Don't Overlap");
    return 0;
    return 0;
}

