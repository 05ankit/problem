class Solution
{
    public:
    void topViewOfTree(Node *root,int a,int b,map<int,int> &topview,map<int,int> &level )
    {
        if(root==NULL)
        {
        return ;
        }
        if(topview.find(a)==topview.end())
        {
            topview[a]=root->data;
            level[a]=b;
        }
        else
        {
            if(level[a]>=b)
            {
                topview[a]=root->data;
                level[a]=b;
            }
        }
        topViewOfTree(root->right,a+1,b+1,topview,level);
        topViewOfTree(root->left,a-1,b+1,topview,level);
       
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> topview;
        map<int,int> level;
        vector<int> ans;
        topViewOfTree(root,0,0,topview,level);
        map<int,int>::iterator i=topview.begin();
        while(i!=topview.end())
        {
            ans.push_back(i->second);
            i++;
        }
        return ans;
    }

};
