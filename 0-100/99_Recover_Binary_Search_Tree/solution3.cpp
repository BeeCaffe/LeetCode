/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法三：
 *      思路同解法2，这里不再赘述，只是采用的是中序遍历的非递归形式。
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
    void recoverTree(TreeNode* root) {
        TreeNode *pre=nullptr,*first=nullptr,*second=nullptr;
        stack<TreeNode* > stk;
        TreeNode* node=root;
        while(!stk.empty() || node!=nullptr){
            if(node!=nullptr){
                stk.push(node);
                node=node->left;
            }else{
                node=stk.top();
                stk.pop();
                if(pre!=nullptr){
                    if(pre->val > node->val){
                        if(first==nullptr) first=pre;
                        second=node;
                    }
                }
                pre=node;
                node=node->right;
            }
        }
        swap(first->val,second->val);
    }
};