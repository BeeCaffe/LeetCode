/***********************************************************************************************************************
 * Author: BeeCaffe.
 * GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
 *
***********************************************************************************************************************/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        res.push_back(vector<int>());
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            help(nums,i+1,res,tmp);
            tmp.pop_back();
        }
        return res;
    }

    void help(vector<int>& nums,int index,vector<vector<int>>& res,vector<int> tmp){
        if(index==nums.size()) return;
        else{
            for(int i=index;i<nums.size();++i){
                if(nums[i]!=nums[i-1]){
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                    help(nums,i+1,res,tmp);
                    tmp.pop_back();
                }else if(nums[i]==nums[i-1]&&i==index){
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                    help(nums,i+1,res,tmp);
                    tmp.pop_back();
                }else continue;
            }
        }
    }
};