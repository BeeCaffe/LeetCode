//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findMax(nums,0,nums.size()-1);
    }
    int findMax(vector<int>& nums,int left,int right){
        if(left>=right) return nums[left];
        int mid=left+(right-left)/2;
        int lmax=findMax(nums,left,mid-1);
        int rmax=findMax(nums,mid+1,right);
        int sum=nums[mid];
        int mmax=sum;
        for(int i=mid-1;i>=left;i--){
            sum+=nums[i];
            mmax = mmax>sum ? mmax:sum;
        }
        sum=mmax;
        for(int i=mid+1;i<=right;i++){
            sum+=nums[i];
            mmax = mmax>sum ? mmax:sum;
        }
        return max(mmax,max(lmax,rmax));
    }
};