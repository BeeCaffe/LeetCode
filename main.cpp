#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    public:
           static     double findMaxAverage(vector<int>& nums, int k) {
               double sum=0;
               for(int i=0;i<k;++i) sum+=nums[i];
               double average=sum/k;
               for(int i=1;i<nums.size()-k;++i){
                   sum=sum-nums[i-1]+nums[i+k];
                   average=max(average,sum/k);
               }
               return average;
           }
        };

int main() {
    vector<int> nums={1,12,-5,-6,50,3};
    Solution::findMaxAverage(nums,4);
    return 0;
}