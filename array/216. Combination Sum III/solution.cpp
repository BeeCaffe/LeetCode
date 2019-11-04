/***********************************************************************************************************************
 * Created by caffe on 2019/11/4.
 * 题干：
 *      Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can
 *      be used and each combination should be a unique set of numbers.
        Note:
            All numbers will be positive integers.
            The solution set must not contain duplicate combinations.
 **********************************************************************************************************************/
/**
 * solution1:dfs(深度优先搜索)
 *      找出所有可能的k个数的组合，将和等于n的结果记录下来，最后返回。(开心，这还是个最优解)
 *      Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
 *      Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Combination Sum III.
 * 时间复杂度：O(logn)
 * 空间复杂度：O(n);
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k==0) return {};
        vector<vector<int>> res;
        vector<int> sig;
        help(k,n,res,sig,0,1,10);
        return res;
    }
    void help(int &k,int &n,vector<vector<int>> &res,vector<int> &sig,int level,int beg,int end){
        level++;
        if(level>k) return;
        for(int i=beg;i<end;++i){
            sig.push_back(i);
            if(level==k){
                int sum=0;
                for(int j=0;j<k;++j) sum+=sig[j];
                if(sum==n) res.push_back(sig);
            }else{
                help(k,n,res,sig,level,i+1,end);
            }
            sig.pop_back();
        }
    }
};