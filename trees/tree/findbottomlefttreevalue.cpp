class Solution {
public:
    void bottomLeftValue(TreeNode *root,int currentheight,int &maximumheight,int &value)
    {
        if(root==NULL)
        return ;
        if(root->left==NULL&&root->right==NULL)  
        {
            if(currentheight>maximumheight) 
            {
                value=root->val;
                maximumheight=currentheight;
            }
        }
        
         bottomLeftValue(root->left,currentheight+1,maximumheight,value);
         bottomLeftValue(root->right,currentheight+1,maximumheight,value);
         
    }
    int findBottomLeftValue(TreeNode* root) {
        int value=root->val;
        int maxheight=0;
        bottomLeftValue(root,0,maxheight,value);
        return value;
    }
};