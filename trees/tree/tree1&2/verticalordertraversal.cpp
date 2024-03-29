class Solution {
public:
 map<int,vector<pair<int,int>>> answer;  
    void traverse(TreeNode *root,int pos,int h)
    {
       if(root==NULL)
       return ;
       answer[pos].push_back(pair<int,int>(h,root->val)); 
       traverse(root->left,pos-1,h+1);
       traverse(root->right,pos+1,h+1); 

    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        traverse(root,0,0); //call function
        vector<vector<int>> verticalTraverse; 
         map<int, vector<pair<int,int>>>::iterator itr=answer.begin(); 
         while(itr!=answer.end())
         {
            vector<int> temp;
            sort(itr->second.begin(),itr->second.end()); 
            for(int i=0;i<itr->second.size();i++)
            temp.push_back(itr->second[i].second); 
            verticalTraverse.push_back(temp);
            itr++;
         }
        return verticalTraverse;
    }
};
