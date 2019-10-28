/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法二：层次遍历变形
 *      如方法一，采用层次遍历，记录遍历的层数，当level为偶数的时候，反序放置元素即可，即：每次遍历我们都可以知道ector的长度，
 *      因此， 当为偶数层时，节点值应当加入到size-1-i的位置处，这样就相当于手动反序了元素，节省了调用reverse函数的时间。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode* > que;
        que.push(root);
        int level=1;
        while(!que.empty()){
            int size=que.size();
            vector<int> tmp(size);
            for(int i=0;i<size;++i){
                TreeNode *node=que.front();
                que.pop();
                if(level%2==0){
                    tmp[size-1-i]=node->val;
                }else{
                    tmp[i]=node->val;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(tmp);
            ++level;
        }
        return res;
    }
};