/***********************************************************************************************************************
 * Author: BeeCaffe.
 * GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
 *
***********************************************************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    static vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        travel(root,res);
        return res;
    }

    static void travel(TreeNode* root,vector<int> res){
        if(root==NULL) return;
        res.push_back(root->val);
        travel(root->left,res);
        travel(root,res);
        travel(root->right,res);
    }
};

int main(){
    TreeNode node3(3);
    TreeNode node2(2);
    TreeNode node1(1);
    node1.left=NULL;
    node1.right=&node2;
    node2.left=&node3;
    node2.right=0;
    node3.left=node3.right=NULL;
    vector<int> res=Solution::inorderTraversal(&node1);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}