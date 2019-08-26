//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
//1.暴力解法
//  将可以到达的位置标记为1，依次遍历每一个位置，如果该位置可以到达，以其为起点跳，最后检查最后一个位置是否可以到达。
//  时间复杂度为0(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz=nums.size();
        vector<int> mask(sz,0);
        mask[0]=1;
        for(int i=0;i<sz;i++){
            if(mask[i]){
                for(int j=1;j<=nums[i];j++){
                    if(i+j<sz) mask[i+j]=1;
                }
            }
        }
        return mask[sz-1]==1 ? true:false;
    }
};