class Solution {
 public:
  TreeNode* invertTree(TreeNode* node) {
    if (node == nullptr)
      return nullptr;

    TreeNode* const left = node->left;
    TreeNode* const right = node->right;
    node->left = invertTree(right);
    node->right = invertTree(left);
    return node;
  }
};
