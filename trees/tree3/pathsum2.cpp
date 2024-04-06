class Solution {
public:
 vector<vector<int>> answer;
    void allPath(TreeNode *rootnode,int tSum,vector<int> path)
    {
        if(rootnode==NULL)
        {
        return ;
        }
        if(rootnode->left==NULL&&rootnode->right==NULL)
        {
            tSum-=rootnode->val;
            if(tSum==0)
            {
               path.push_back(rootnode->val);
               answer.push_back(path);
            }
        }
        path.push_back(rootnode->val);
        allPath(rootnode->left,tSum-rootnode->val,path);
        allPath(rootnode->right,tSum-rootnode->val,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        allPath(root,targetSum,path);
        return answer;
    }
};
