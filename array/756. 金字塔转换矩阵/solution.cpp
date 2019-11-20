/***********************************************************************************************************************
 * Created by caffe on 2019/11/19.
 * 756. 金字塔转换矩阵
 * 现在，我们用一些方块来堆砌一个金字塔。 每个方块用仅包含一个字母的字符串表示，例如 “Z”。
    使用三元组表示金字塔的堆砌规则如下：

    (A, B, C) 表示，“C”为顶层方块，方块“A”、“B”分别作为方块“C”下一层的的左、右子块。当且仅当(A, B, C)是被允许的三元组，我们才可以将其堆砌上。

    初始时，给定金字塔的基层 bottom，用一个字符串表示。一个允许的三元组列表 allowed，每个三元组用一个长度为 3 的字符串表示。

    如果可以由基层一直堆到塔尖返回true，否则返回false。

    示例 1:

    输入: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
    输出: true
    解析:
    可以堆砌成这样的金字塔:
        A
       / \
      D   E
     / \ / \
    X   Y   Z

    因为符合('X', 'Y', 'D'), ('Y', 'Z', 'E') 和 ('D', 'E', 'A') 三种规则。

    示例 2:

    输入: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
    输出: false
    解析:
    无法一直堆到塔尖。
    注意, 允许存在三元组(A, B, C)和 (A, B, D) ，其中 C != D.

    注意：

        bottom 的长度范围在 [2, 8]。
        allowed 的长度范围在[0, 200]。
        方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}。``
 **********************************************************************************************************************/
/**
 * solution 1 : 递归算法
 *
 */
 //这个题目AC太不容易了！！！
class Solution {
public:
    static bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> mp;
        for(string str:allowed){
            string str_tmp=str.substr(0,2);
            if(mp.find(str_tmp)==mp.end()){
                mp.insert(pair<string,string>(str_tmp,str.substr(2)));
            }else{
                mp.find(str_tmp)->second+=str.substr(2);
            }
        }
        string next;
        return assist(bottom,next,mp);
    }

    static bool assist(string level,string nextlevel,unordered_map<string,string> &hash_map){
        if(level.size()==2&&nextlevel.size()==1) return true;
        for(int i=nextlevel.size()+1;i<level.size();++i){
            string base_str=level.substr(i-1,2);
            auto iter=hash_map.find(base_str);
            if(iter==hash_map.end()) return false;
            else{
                string tmp_str=iter->second;
                for(int j=0;j<tmp_str.size();++j){
                    nextlevel+=tmp_str[j];
                    if(assist(level,nextlevel,hash_map)) return true;
                    else nextlevel=nextlevel.substr(0,nextlevel.size()-1);
                }
                return false;
            }
        }
        level=nextlevel;
        nextlevel="";
        return assist(level,nextlevel,hash_map);
    }
};