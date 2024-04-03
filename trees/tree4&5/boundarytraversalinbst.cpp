void leftboundary(TreeNode<int>* rootnode,vector<int> &boundary)
{
  if (rootnode == NULL) {
    return;
  }
    while(rootnode->left!=NULL||rootnode->right!=NULL)
    {
        boundary.push_back(rootnode->data);
        if(rootnode->left!=NULL)
        {
            rootnode=rootnode->left;
        }
        else
        rootnode=rootnode->right;
    }
}
void bottomboundary(TreeNode<int> *root,vector<int> &boundary)
{
    if (root == NULL) {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        boundary.push_back(root->data);
    }
    bottomboundary(root->left,boundary);
    bottomboundary(root->right,boundary);
}
void rightboundary(TreeNode<int> *root,vector<int> &boundary)
{
    int c=0;
    if(root==NULL)
    return ;
     while(root->left!=NULL||root->right!=NULL)
    {
        boundary.push_back(root->data);
        c++;
        if(root->right!=NULL)
        {
            root=root->right;
        }
        else
        root=root->left;
    }
    reverse(boundary.begin()+boundary.size()-c,boundary.end());
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> boundary;
    boundary.push_back(root->data);
    leftboundary(root->left,boundary);
    bottomboundary(root,boundary);
    rightboundary(root->right,boundary);
    return boundary;
}
