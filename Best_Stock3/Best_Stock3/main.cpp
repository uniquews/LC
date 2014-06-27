//
//  main.cpp
//  Best_Stock3
//
//  Created by Shuai Wang on 6/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())  return 0;
        
        int day =  prices.size();
        vector<int> max1 (day, 0);
        
        int minVal = prices[0];
        
        max1[0] = 0;
        
        for(int i=1; i<day; i++){
            if(minVal > prices[i])
                minVal = prices[i];
            
            max1[i] = max((prices[i] - minVal), max1[i-1]);
        
        }
        
//        for (int i=0; i< max1.size(); i++){
//            cout << max1[i] << " ";
//        }
        int max_profit=0;
        int _max = INT_MIN;
        int _min = INT_MAX;

        int tempProfit = 0;
        if(day ==1){
            max_profit = max1[0];
        }else{
            //如果最后一个和之前的差很大，那么单单最后一天卖一次就可以是最大收入，所以max_profit要初始化这样
            max_profit = max(max1[day-1], max1[day-2]);
            if(prices[day-1] > prices[day-2]){
                tempProfit =prices[day-1] - prices[day-2];;
                _max = prices[day-1];
                _min = prices[day-2];
            
            }else{
                
                //2,1,4,5,2,9,7
                _max = prices[day-2];
                //_min要以9为界，所以不能初始化成7
                _min = _max;
            }
            
        }
        
        

        
        
        for(int i=day-3; i>=0; i--){
            //必须要先更新_min
            if(prices[i] <  _min){
                _min = prices[i];
            }
            
            tempProfit = _max - _min;
            if(tempProfit + max1[i] > max_profit)
                max_profit = tempProfit+ max1[i];

            if(prices[i]>_max){
                _max = prices[i];
                _min = _max;
            }
            
            
        }
        
        
        return max_profit;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Solution s;
    vector<int> price = {2,1,2,0,1};
    cout << s.maxProfit(price);
    return 0;
}

