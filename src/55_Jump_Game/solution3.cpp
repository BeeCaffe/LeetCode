//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 3.贪心算法
 *   求每个位置所能到的最远位置，如果最远位置小于当前位置或者大于数组长度就跳出循环。
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz=nums.size();
        int reach=0;
        for(int i=0;i<sz;i++){
            if(reach<i || reach>sz-1)
                break;
            if(reach<nums[i]+i)
                reach=nums[i]+i;
        }
        return reach>=sz-1 ? true:false;
    }
};
