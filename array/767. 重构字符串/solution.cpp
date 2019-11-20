/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 * 767. 重构字符串
 * 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

    若可行，输出任意可行的结果。若不可行，返回空字符串。

    示例 1:

    输入: S = "aab"
    输出: "aba"

    示例 2:

    输入: S = "aaab"
    输出: ""

    注意:

        S 只包含小写字母并且长度在[1, 500]区间内。
 **********************************************************************************************************************/
/**
 * solution 1 : map法
 * 执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
 * 内存消耗 :8.4 MB, 在所有 cpp 提交中击败了87.30%的用户
 * 将所有字母按照出现频率进行排序，先将出现频率最高的两个进行组合，这样可以保证不重复。当当前出现频率第二高的字母被用完了之后，重新进行排序，
 * 继续组合出现频率最高的两个字母。当只剩下一种字母的时候，并且该字母的个数大于1，就返回空字符串。否则就返回结果
 * 时间复杂度： O（n）每个字母都要被排一次
 * 空间复杂度： O（m）m为出现字母的种类数目
 */
class Solution {
public:
    static bool cmp(const pair<char,int> &a,const pair<char,int> &b){
        return a.second>b.second;
    }
    static string reorganizeString(string S) {
        map<char,int> table_map;
        for(int i=0;i<S.size();++i){
            if(table_map.find(S[i])==table_map.end()) table_map.insert(pair<char,int>(S[i],1));
            else table_map.find(S[i])->second++;
        }
        vector<pair<char,int>> table(table_map.begin(),table_map.end());
        sort(table.begin(),table.end(),cmp);
        string ans;
        while(table.size()>0){
            for(int i=0;i<2;++i){
                if(i<table.size()&&table[i].second!=0){
                    ans+=table[i].first;
                    table[i].second--;
                }
                if(i<table.size() && table[i].second==0){
                    table.erase(table.begin()+i);
                    sort(table.begin(),table.end(),cmp);
                }
            }
            if(table.size()==1&&table.begin()->second>1) return "";
        }
        return ans;
    }
};