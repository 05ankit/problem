class Solution {
public:
    int diameterOfBinaryTree(TreeNode* node) {
        int d=0;
        rec(node, d);
        return d;
    }
    int rec(TreeNode* rnode, int &d) {
        if(rnode == NULL) return 0;
        int ld = rec(rnode->left, d);
        int rd = rec(rnode->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
};
