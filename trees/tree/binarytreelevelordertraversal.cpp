class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> res;
        queue<TreeNode*> q;
        if(root==NULL)
        return result;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
         struct TreeNode *temp=q.front();
           q.pop();
          if(temp==NULL)
          {  
              q.push(NULL);
              result.push_back(res);
              res.clear();
              temp=q.front();
              q.pop();
              if(temp==NULL)
              {
                  q.pop();
                  break;
              }

          }
          
          if(temp->left!=NULL)
          {
          q.push(temp->left);
          }
          if(temp->right!=NULL)
          {
          q.push(temp->right);
          }
          res.push_back(temp->val);
          
        }
        return result;
    }
};