class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        stack<int> up;
        TreeNode *node=new TreeNode(preorder[0]);
        st.push(node);
        up.push(INT_MAX);
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode* temp=st.top();
            if(temp->val>preorder[i])
            {
              temp->left=new TreeNode(preorder[i]);
              up.push(temp->val);
              st.push(temp->left);
            }
            else
            {
                int t=up.top();
               while(t<preorder[i])
               {
                 up.pop();
                 st.pop();
                 t=up.top();
               }
               temp=st.top();
               temp->right=new TreeNode(preorder[i]);
               st.push(temp->right);
               up.push(up.top());
            }
        }
        return node;
        
    }
};
