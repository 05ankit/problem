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
    TreeNode* lowestCommonAncestor(TreeNode* rootnode, TreeNode* p, TreeNode* q) 
    {
        if(rootnode==p||rootnode==q||(p->val<rootnode->val&&q->val>rootnode->val)||(q->val<rootnode->val&&p->val>rootnode->val))
        {
        return rootnode;
        }
        if(p->val<rootnode->val)
        {
        return lowestCommonAncestor(rootnode->left,p,q);
        }
        else
        {
       return lowestCommonAncestor(rootnode->right,p,q);
        }
    }
};
