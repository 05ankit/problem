class Solution {
public:
    void helper(TreeNode* root,vector<string>& result,string current){
        if(!root)return;
        if(root->left||root->right)current+=(to_string(root->val)+"->");
        else{
            current+=(to_string(root->val));
            result.push_back(current);
        }
        helper(root->left,result,current);
        helper(root->right,result,current);  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string current="";
        helper(root,result,current);
        return result;
    }
};
