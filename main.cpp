#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    static int findUnsortedSubarray(vector<int>& nums) {
        int pst=0,pend=nums.size();
        while(pst<pend){
            while(pst<pend && ismin(nums,nums[pst],pst+1,pend)) ++pst;
            while(pst<pend && ismax(nums,nums[pend-1],pst,pend-1)) --pend;
        }
        return pend-pst;
    }

    static bool ismin(vector<int> &nums,int key,int left,int right){
        for(int i=left;i<right;++i){
            if(key>nums[i]) return false;
        }
        return true;
    }
    static bool ismax(vector<int> &nums,int key,int left,int right){
        for(int i=right-1;i>=left;--i){
            if(key<nums[i]) return false;
        }
        return true;
    }
};

int main() {
    vector<int> nums={2, 6, 4, 8, 10, 9, 15};
    Solution::findUnsortedSubarray(nums);
    return 0;
}