class Solution {
public:
    int s=0;
    int inorder(TreeNode* rootnode,int L,int R){
        if(rootnode){
        inorder(rootnode->left,L,R);
        if(rootnode->val>=L && rootnode->val<=R)
            s+=rootnode->val;
        inorder(rootnode->right,L,R);
        }
        return s;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)return 0;
        return inorder(root,L,R);
    }
};
