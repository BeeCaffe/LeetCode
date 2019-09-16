//
// Created by Administrator on 2019/8/8.
//
#include <vector>
using namespace std;
/**
 * as a result of this problem requires solving it in Olog(n), so I suppose to use Binary search
 * to slove this problem, there are four type of mid and target's location status
 * 1. mid and target are both in left side.
 * 2. mid and target are both in right side.
 * 3. mid in left side and target in right side.
 * 4. mid in right side and target in left side.
 * considering those four possibilities , you can solve this problem
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid = (left+right)/2;
            if(target==nums[mid]) return mid;
            if(nums[mid]>=nums[left]){
                //both in left side
                if(target>=nums[left]){
                    if(nums[mid]>target) right=mid-1;
                    else left=mid+1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]<=nums[right]) {
                //both in right side.
                if(target<=nums[right]){
                    if(nums[mid]>target) right=mid-1;
                    else left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};