//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 *
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN;
        vector<int> arr_max;
        for(int i=0;i<nums.size();i++){
            int sum=0,local_max=INT_MIN;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                local_max=local_max>sum ? local_max:sum;
            }
            arr_max.push_back(local_max);
        }
        for(auto data:arr_max){
            max= data>max ? data:max;
        }
        return max;
    }
};
