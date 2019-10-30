/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
 *      Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
                                         [1],
                                        [1,1],
                                       [1,2,1],
                                      [1,3,3,1],
                                     [1,4,6,4,1]
 * 解法一：递归法
 *      每一层的首尾都是一，中间的数值是前后两个相加的和。
 *      i=1，构造[1]
 *      i=2,构造[1,1]
 *      i=k，前后插入1，中间为上一层前后数字之和
 *      i>n，结束
 * 时间复杂度：因为一共递归n次，每次递归右n-1次循环，O（n2）
 * 空间复杂度：一个vector存储结果，每次递归又产生一个临时的vector，O（n2）
 **********************************************************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return {};
        vector<vector<int>> res;
        int n=1;
        create(res,n,numRows);
        return res;
    }

    void create(vector<vector<int>> &res,int n,int numRows){
        vector<int> tmp;
        if(n>numRows) return;
        if(n==1){
            tmp.push_back(1);
        }else if(n==2){
            tmp.push_back(1);
            tmp.push_back(1);

        }else{
            tmp.push_back(1);
            for(int i=0;i<n-2;++i){
                int val=res[n-2][i]+res[n-2][i+1];
                tmp.push_back(val);
            }
            tmp.push_back(1);
        }
        res.push_back(tmp);
        create(res,n+1,numRows);
    }
};