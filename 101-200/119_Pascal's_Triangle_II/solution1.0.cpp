/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
 *      Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 *      Note that the row index starts from 0.
 * 解法一：迭代法
 *       当i=1或i=2的时候直接返回
 *       否则，用一个临时的vector记录上一层的节点情况，用来计算这一层的节点情况。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last={1,1};
        if(rowIndex==0){
            return vector<int>({1});
        }
        if(rowIndex==1){
            return vector<int>({1,1});
        }
        for(int i=2;i<=rowIndex;++i){
            vector<int> cur;
            cur.push_back(1);
            for(int j=0;j<i-1;++j){
                int val=last[j]+last[j+1];
                cur.push_back(val);
            }
            cur.push_back(1);
            last=cur;
        }
        return last;
    }
};