class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
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
                if(i>index&&v[i]==v[i-1]) continue;
                temp.push_back(v[i]);
                find(v,target-v[i],i+1,temp,res);
                temp.pop_back();
            }
        }
    }
};
