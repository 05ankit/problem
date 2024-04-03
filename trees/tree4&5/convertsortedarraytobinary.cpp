class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;
        if(num.size() == 1)
        {
            return new TreeNode(num[0]);
        }
        
        int middle = num.size()/2;
        TreeNode* rootnode = new TreeNode(num[middle]);
        
        vector<int> leftInts(num.begin(), num.begin()+middle);
        vector<int> rightInts(num.begin()+middle+1, num.end());
        
        rootnode->left = sortedArrayToBST(leftInts);
        rootnode->right = sortedArrayToBST(rightInts);
        
        return rootnode;
    }
};
