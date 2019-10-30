/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
 *      将一个完美二叉树每一层用一个next指针连接起来，切每一层的最后一个节点的next指针指向nullptr
 * 解法一：层次遍历
 *      层次遍历二叉树，将每一层连接起来即可。
 * 时间复杂度：显然就是层次遍历的时间复杂度O（n）
 * 空间复杂度：因为使用了一个辅助队列，因此是O（n）
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
        queue<Node *> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            Node *pre_node=que.front();
            Node *node=pre_node;
            que.pop();
            if(pre_node->left) que.push(pre_node->left);
            if(pre_node->right) que.push(pre_node->right);
            for(int i=1;i<size;++i){
                node=que.front();
                que.pop();
                pre_node->next=node;
                pre_node=node;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            node->next=nullptr;
        }
        return root;
    }
};