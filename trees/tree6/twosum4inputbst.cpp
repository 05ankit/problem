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
    bool findTarget(TreeNode* rootnode, int k) {
        vector<int> num;
        inorder(rootnode, num);
        return findTargetInSortedArray(num, k);
    }
    void inorder(TreeNode* node, vector<int>& nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }

    bool findTargetInSortedArray(vector<int> a, int key) {
        int n=a.size()-1;
        for (int i = 0, j = n; i < j;) {
            int sum = a[i] + a[j];
            if (sum == key) 
            {
                return true;
            }
            else if (sum < key) 
            {
                i++;
            }
            else 
            {
                j--;
            }
        }

        return false;
    }
};
