class Solution {
public:
    bool SameTree(TreeNode* a, TreeNode* b) {
        if(a==NULL&&b==NULL)
        return true;
        if((a==NULL||b==NULL)||(a->val!=b->val))
        return false;
        return  SameTree(a->left,  b->left) && SameTree(a->right,  b->right);
    }
};