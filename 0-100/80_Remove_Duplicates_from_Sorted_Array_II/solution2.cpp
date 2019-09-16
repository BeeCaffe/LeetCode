//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * @name direct solve
 * @brief
 *  1.Set a index 'idx' to record the new array.
 *  2.Go through the array 'nums', if the continuous number less than 3,nums[idx++]=nums[i],else jump.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.empty()) return 0;
        int idx=0,count=1;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i]){
                count++;
                if(count>=3) continue;
            }else{
                count=1;
            }
            nums[idx++]=nums[i];
        }
        return idx;
    }
};