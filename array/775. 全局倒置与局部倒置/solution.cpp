/***********************************************************************************************************************
 * Created by caffe on 2019/11/21.
 * 775. 全局倒置与局部倒置
 * 数组 A 是 [0, 1, ..., N - 1] 的一种排列，N 是数组 A 的长度。全局倒置指的是 i,j 满足 0 <= i < j < N 并且 A[i] > A[j] ，局部倒置指的是 i 满足 0 <= i < N 并且 A[i] > A[i+1] 。

    当数组 A 中全局倒置的数量等于局部倒置的数量时，返回 true 。

    示例 1:

    输入: A = [1,0,2]
    输出: true
    解释: 有 1 个全局倒置，和 1 个局部倒置。

    示例 2:

    输入: A = [1,2,0]
    输出: false
    解释: 有 2 个全局倒置，和 1 个局部倒置。

    注意:
        A 是 [0, 1, ..., A.length - 1] 的一种排列
        A 的长度在 [1, 5000]之间
        这个问题的时间限制已经减少了。
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 思路
    将 'L'，'R' 分别理解为一个队伍中面向左和面向右的人，'X' 理解为队伍中的空挡。可以问自己一个问题，一次移动操作之后有什么是保持不变的？ 这是状态转换问题中一个很常见的思路。
    算法
    这道题的 转换不变性 在于字符串中的 'L' 和 'R' 是不会互相穿插的，也就是队伍中的人在移动过程中是不能穿过人的。这意味着开始和结束的字符串如果只看 'L' 和 'R' 的话是一模一样的。
    除此之外，第 n 个 'L' 不可能移动到初始位置的右边，第 n 个 'R' 不可能移动到初始位置的左边，我们把这个特性称为 “可到达性“。设 (i1,i2,⋯ )(i_1, i_2, \cdots )(i1​,i2​,⋯)，(i1′,i2′,⋯ )(i^{'}_1, i^{'}_2, \cdots )(i1′​,i2′​,⋯) 为每个字符 'L' 在原始字符串和目标字符串的位置，(j1,j2,⋯ )(j_1, j_2, \cdots )(j1​,j2​,⋯)，(j1′,j2′,⋯ )(j^{'}_1, j^{'}_2, \cdots )(j1′​,j2′​,⋯) 为每个字符 'R' 在原始字符串和目标字符串的位置，如果 ik≥ik′i_k \geq i^{'}_kik​≥ik′​ 和 jk≤jk′j_k \leq j^{'}_kjk​≤jk′​ 都能满足，这个字符串就是 ”可到达的“。
    根据 转换不变性 和 可到达性，在算法中可以分别检查这两个性质是否满足。如果都满足，则返回 True，否则返回 False。
 * 时间复杂度： O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    bool canTransform(string start, string end) {
        string tmpstart(start);
        string tmpend(end);
        for(auto iter=tmpstart.begin();iter<tmpstart.end();++iter){
            if(*iter=='X'){
                tmpstart.erase(iter);
                --iter;
            }
        }
        for(auto iter=tmpend.begin();iter<tmpend.end();++iter){
            if(*iter=='X'){
                tmpend.erase(iter);
                --iter;
            }
        }
        if(tmpstart!=tmpend) return false;
        int idx=0;
        for(int i=0;i<start.size();++i){
            if(start[i]=='L'){
                while(idx<end.size()&&end[idx]!='L') ++idx;
                if(i<idx++) return false;
            }
        }
        idx=0;
        for(int i=0;i<start.size();++i){
            if(start[i]=='R'){;
                while(idx<start.size()&&end[idx]!='R') ++idx;
                if(i>idx++) return false;
            }
        }
        return true;
    }
};
/**
 * solution 2 : 双指针法
 * 思路和上面完全一样。
 * 时间复杂度： O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    bool canTransform(string start, string end) {
        int p1=-1,p2=-1;
        int sz=start.size();
        while(++p1<sz&&++p2<sz){
            while(p1<sz&&start[p1]=='X') ++p1;
            while(p2<sz&&end[p2]=='X') ++p2;
            if((p1<sz)^(p2<sz)) return false;
            if(p1<sz&&p2<sz){
                if(start[p1]!=end[p2] || (start[p1]=='L'&&p1<p2) || (start[p1]=='R'&&p1>p2)) return false;
            }
        }
        return true;
    }
};