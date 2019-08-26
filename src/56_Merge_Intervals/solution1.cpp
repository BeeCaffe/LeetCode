//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.暴力算法
 *   1）先根据第一个数按照从小到大排序
 *   2）从前往后依次合并
 */
class Solution {
public:
    static bool comp(vector<int>& inter1,vector<int>& inter2){
        return inter1[0]<inter2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz=intervals.size();
        vector<vector<int>> res;
        if(sz==0) return res;
        sort(intervals.begin(),intervals.end(),comp);
        res.push_back(intervals[0]);
        for(int i=1;i<sz;i++){
            int sz_=res.size()-1;
            if(res[sz_][1]>=intervals[i][0]){
                res[sz_][1]=max(intervals[i][1],res[sz_][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};