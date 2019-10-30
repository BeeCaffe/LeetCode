/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
 *      这回时将任意一棵二叉树的每一层用一个next指针连接起来。
 * 解法一：层次遍历
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        queue<Node* > que;
        que.push(root);
        while(!que.empty()){
            int sz=que.size();
            Node *prenode=que.front();
            Node *node=prenode;
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            for(int i=1;i<sz;++i){
                node=que.front();
                que.pop();
                prenode->next=node;
                prenode=node;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            node->next=nullptr;
        }
        return root;
    }
};