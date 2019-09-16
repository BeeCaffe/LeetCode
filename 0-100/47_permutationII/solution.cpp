//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * @brief : Here we taken recursion DFS as well, but there is some differences from permutation.We must ensure
 *          that there is no duplicated in the final result,I have taken two method to solve this problem.
 *          1. sort the initial array to keep that duplicated number is adjacent.
 *          2. each recursion times record the traveled numbers location in the 'mask', if the duplicated number
 *             in the 'nums' is not follow the order, we discard this result.
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<int> mask(nums.size());
        std::sort(nums.begin(),nums.end());
        find(nums,mask,nums.size(),temp,res);
        return res;
    }

    void find(vector<int>& nums,vector<int>& mask,int n,vector<int>& temp,vector<vector<int>>& res){
        if(n==0){
            vector<int>& tmp(temp);
            res.push_back(temp);
            return;
        }else if(n>0){
            for(int i=0,index=1;i<nums.size();i++,index++){
                //if is duplicated
                if(i>0&&nums[i]==nums[i-1]){
                    //if the order is not right, discard this solution
                    if(mask[i]<mask[i-1]) continue;
                }
                if(mask[i]==0){
                    mask[i]=index;
                    temp.push_back(nums[i]);
                    find(nums,mask,n-1,temp,res);
                    mask[i]=0;
                    temp.pop_back();
                }
            }

        }
    }
};