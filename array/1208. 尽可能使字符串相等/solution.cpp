/***********************************************************************************************************************
 * Created by caffe on 2019/12/9.
 * 1208. 尽可能使字符串相等
 * 给你两个长度相同的字符串，s 和 t。

    将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

    用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

    如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

    如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。



    示例 1：

    输入：s = "abcd", t = "bcdf", cost = 3
    输出：3
    解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。

    示例 2：

    输入：s = "abcd", t = "cdef", cost = 3
    输出：1
    解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。

    示例 3：

    输入：s = "abcd", t = "acde", cost = 0
    输出：1
    解释：你无法作出任何改动，所以最大长度为 1。



    提示：

        1 <= s.length, t.length <= 10^5
        0 <= maxCost <= 10^6
        s 和 t 都只含小写英文字母。
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针
 * 时间复杂度： O（n2）
 * 空间复杂度： O（n）
 */
//Time  Limit Exceed
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> dist(s.size());
        for(int i=0;i<s.size();++i){
            dist[i]=abs(t[i]-s[i]);
        }
        int left=0,right;
        int ans=INT_MIN;
        while(left<dist.size()){
            int sum=0;
            right=left;
            while(right<s.size()&&sum+dist[right]<=maxCost){
                sum+=dist[right];
                ++right;
            }
            ans= max(right-left,ans);
            ++left;
        }
        return ans;
    }
};
/**
 * solution 1 ： 滑动窗口
 * 注意窗口应该一直缩小到满足要求为止。
 * 时间复杂度： O（n）
 * 空间复杂度: O(n)
 */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> dist(s.size());
        for(int i=0;i<s.size();++i){
            dist[i]=abs(t[i]-s[i]);
        }
        int ans=0;
        int sum=0,left=0;
        for(int i=0;i<dist.size();++i){
            sum+=dist[i];
            while(sum>maxCost) sum-=dist[left++];
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};