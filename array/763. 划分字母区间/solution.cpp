/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 * 763. 划分字母区间
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

    示例 1:
    输入: S = "ababcbacadefegdehijhklij"
    输出: [9,7,8]
    解释:
    划分结果为 "ababcbaca", "defegde", "hijhklij"。
    每个字母最多出现在一个片段中。
    像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

    注意:

        S的长度在[1, 500]之间。
        S只包含小写字母'a'到'z'。
 **********************************************************************************************************************/
/**
 * solution 1:贪心算法，双指针
 * 策略就是不断地选择从最左边起最小的区间。可以从第一个字母开始分析，假设第一个字母是 'a'，那么第一个区间一定包含最后一次出现的 'a'。但第一
 * 个出现的 'a' 和最后一个出现的 'a' 之间可能还有其他字母，这些字母会让区间变大。举个例子，在 "abccaddbeffe" 字符串中，第一个最小的区间是
 * "abccaddb"。通过以上的分析，我们可以得出一个算法：对于遇到的每一个字母，去找这个字母最后一次出现的位置，用来更新当前的最小区间。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size()==1) return {1};
        vector<int> ans;
        int pbeg=0,pend=S.size();
        while(pbeg<S.size()){
            pend=S.size()-1;
            while(pbeg<=pend&&S[pbeg]!=S[pend]) --pend;
            for(int i=pbeg;i<=pend;++i){
                int left=i,right=S.size()-1;
                while(left<right&&S[left]!=S[right]) --right;
                if(pend<right) pend=right;
            }
            ans.push_back(pend-pbeg+1);
            pbeg=pend+1;
        }
        return ans;
    }
};