/***********************************************************************************************************************
 *
 * Created by caffe on 2019/10/30.
 * 解法二：迭代法
 *      思路同递归法一样，只是知道了每层的迭代次数和上一层的结果，就可以很方便的用迭代法解决。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 **********************************************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {};
        vector<vector<int>> res;
        for(int i=0;i<numRows;++i){
            vector<int> tmp;
            if(i==0){
                tmp.push_back(1);
            }else if(i==1){
                tmp.push_back(1);
                tmp.push_back(1);
            }else{
                tmp.push_back(1);
                for(int j=0;j<i-1;++j){
                    int val=res[i-1][j]+res[i-1][j+1];
                    tmp.push_back(val);
                }
                tmp.push_back(1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};