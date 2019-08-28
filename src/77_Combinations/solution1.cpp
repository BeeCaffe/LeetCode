//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.Recurrent travel
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        help(-1,n,k,temp,res);
        return res;
    }

    void help(int index,int n,int k,vector<int>& temp,vector<vector<int>>& res){
        if(temp.size()==k){
            vector<int> tmp(temp);
            res.push_back(tmp);
            return;
        }else{
            for(int i=index;i<n;i++){
                if(i>index){
                    temp.push_back(i+1);
                    help(i,n,k,temp,res);
                    temp.pop_back();
                }
            }
        }
    }
};