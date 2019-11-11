class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        std::sort(candidates.begin(),candidates.end());
        find(candidates,target,0,temp,res);
        return res;
    }
    
    void find(vector<int>& v,int target,int index,vector<int>& temp,vector<vector<int>>& res){
           if(target==0){
               vector<int> tmp(temp);
               res.push_back(tmp);
           }else if(target<0){
               return;
           }else{
               for(size_t i=index;i<v.size();i++){
                   temp.push_back(v[i]);
                   find(v,target-v[i],i,temp,res);
                   temp.pop_back();
               }
           }
    }
};
