class Solution {
public:
    bool isValidBST(TreeNode* rootnode) {
    return isValidBST(rootnode, NULL, NULL);
}

bool isValidBST(TreeNode* rootnode, TreeNode* minNode, TreeNode* maxNode) {
    if(!rootnode) return true;
    if(minNode && rootnode->val <= minNode->val || maxNode && rootnode->val >= maxNode->val)
        return false;
    return isValidBST(rootnode->left, minNode, rootnode) && isValidBST(rootnode->right, rootnode, maxNode);
}
};
