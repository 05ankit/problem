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
    void solve(TreeNode* rootnode, int &count, int &answer, int k){
        if(rootnode == NULL)    
        {
            return;
        }
        //left, root, right 
        solve(rootnode->left, count, answer, k);
        count++;
        if(count == k)
        {
            answer = rootnode->val;
            return;
        }
        solve(rootnode->right, count, answer, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;        
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
};
