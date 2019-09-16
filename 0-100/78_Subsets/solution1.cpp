//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1. Recurrent
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        help(nums,0,temp,res);
        return res;
    }
    void help(vector<int>& nums,int stindex,vector<int>& temp,vector<vector<int>>& res){
        vector<int> tmp(temp);
        res.push_back(tmp);
        for(int i=stindex;i<nums.size();i++){
            temp.push_back(nums[i]);
            help(nums,i+1,temp,res);
            temp.pop_back();
        }
    }
};