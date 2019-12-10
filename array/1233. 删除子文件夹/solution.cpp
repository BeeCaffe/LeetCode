/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1233. 删除子文件夹
 * 你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

    我们这样定义「子文件夹」：

        如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的子文件夹。

    文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：

        / 后跟一个或者多个小写英文字母。

    例如，/leetcode 和 /leetcode/problems 都是有效的路径，而空字符串和 / 不是。
 **********************************************************************************************************************/
/**
 * solution 1 : set法
 * 先把所有路径名按照长短升序排序，遍历所有路径，并将路径按照‘/’分隔取出前面的根路径rootdir，在set中寻找rootdir，如果找到
 * 则继续，如果没有找到，则将路径加入到set中。最后返回set中的文件路径即可。
 * 时间复杂度： O（nm）
 * 空间复杂度： O（n）
 */
class Solution {
public:
    static bool cmp(const string &str1,const string &str2){
        return str1.size()<str2.size();
    }
    static vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),cmp);
        unordered_set<string> hashset;
        for(string str: folder){
            if(str==""||str=="/") continue;
            string rootdir="";
            bool exists=false;
            for(int i=0;i<str.size();++i){
                if(i!=0&&str[i]=='/') rootdir=str.substr(0,i);
                if(hashset.find(rootdir)!=hashset.end()){
                    exists=true;
                    break;
                }
            }
            if(!exists) hashset.insert(str);
        }
        vector<string> ans(hashset.begin(),hashset.end());
        return ans;
    }
};