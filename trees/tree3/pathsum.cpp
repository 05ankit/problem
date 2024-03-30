class Solution {
 public:
  bool hasPathSum(TreeNode* rnode, int sum) {
    if (rnode == nullptr)
      return false;
    if (rnode->val == sum && rnode->left == nullptr && rnode->right == nullptr)
      return true;
    return hasPathSum(rnode->left, sum - rnode->val) ||
           hasPathSum(rnode->right, sum - rnode->val);
  }
};
