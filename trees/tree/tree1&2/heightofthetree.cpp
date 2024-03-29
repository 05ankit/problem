int heightOfTree(TreeNode<int> *root,int height)
{
    if(root==NULL)
    {
    return height;
    }  
    else
    {
    return max(heightOfTree(root->left,height+1),heightOfTree(root->right,height+1));
    }
}
int heightOfBinaryTree(TreeNode<int> *root)
{
    return heightOfTree(root,0);

}