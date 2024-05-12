/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<pair<TreeNode*,TreeNode*>> recover;
    TreeNode* prev = NULL;
    void inorder(TreeNode* rootnode)
    {
        if(!rootnode) 
        {
            return;
        }
        inorder(rootnode->left);
        if(prev && prev->val>rootnode->val) 
        {
            recover.push_back({prev,rootnode});
        }
        prev = rootnode;
        inorder(rootnode->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(recover.size()==1)
        {
            swap(recover[0].first->val,recover[0].second->val);
        }
        if(recover.size()==2)
        {
            swap(recover[0].first->val,recover[1].second->val);
        }
    }
   
};
