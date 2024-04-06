class Solution {
public:

    void  find(TreeNode *rootnode,TreeNode *node,vector<TreeNode *> ancestor,vector<TreeNode *> &ancestors)
    {
       if(rootnode==NULL)
       {
       return ;
       }
       if(rootnode==node)
       {
         ancestors.push_back(node);
         ancestors=ancestor;
         return ;
       }
       else{
       ancestors.push_back(rootnode);
       find(rootnode->left,node,ancestor,ancestors);
       find(rootnode->right,node,ancestor,ancestors);
       }
     
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> ancestor;
        vector<TreeNode *> ancestorP,ancestorQ;
        find(root,p,ancestor,ancestorP);
        find(root,q,ancestor,ancestorQ);
        int i=0;
        while(i<ancestorP.size()&&i<ancestorQ.size())
        {
            if(ancestorP[i]!=ancestorQ[i])
            {
                break;
            }
            i++;
        }

        return ancestorP[i-1];
    }
};
