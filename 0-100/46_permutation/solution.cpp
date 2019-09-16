//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
#include <vector>
using namespace std;    
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<int> mask(nums.size());
        find(nums,mask,nums.size(),temp,res);
        return res;
    }
    void find(vector<int> &nums,vector<int> &mask,int n,vector<int>& temp,vector<vector<int>>& res){
        if(n==0){
            vector<int> tmp(temp);
            res.push_back(tmp);
            return;
        }else if(n>0){
            for(int i=0;i<mask.size();i++){
                if(mask[i]==0){
                    mask[i]=1;
                    temp.push_back(nums[i]);
                    find(nums,mask,n-1,temp,res);
                    temp.pop_back();
                    mask[i]=0;
                }
            }
        }
    }
};
