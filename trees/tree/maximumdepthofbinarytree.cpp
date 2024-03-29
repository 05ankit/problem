class Solution {
public:
    int depth(TreeNode *root,int d)
    {
        if(root==NULL)
        {
        return d;
        }
        int x=depth(root->right,d+1);
        int y=depth(root->left,d+1);
        return max(x,y);
    }
    int maxDepth(TreeNode* root) {
        return depth(root,0);
    }
};