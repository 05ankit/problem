class Solution{
  public:
    void levelDiff(Node *root,int &oddSum,int &evenSum,int level)
    {
        if(root==NULL)
        return ;
        if(level%2==0)
        {
            evenSum+=root->data;
        }
        else
        {
        oddSum+=root->data;
        }
        levelDiff(root->left,oddSum,evenSum,level+1);
        levelDiff(root->right,oddSum,evenSum,level+1);
        
    }
    int getLevelDiff(Node *root)
    {
       int oddSum=0,evenSum=0;
        levelDiff(root,oddSum,evenSum,1);
        return oddSum-evenSum;
    }
};