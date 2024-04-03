void ceil(Node* rootnode,int input,int &a)
{
    if(rootnode==NULL)
    return ;
    if(rootnode->data>=input)
    {
        a=min(a,rootnode->data);
    }
    ceil(rootnode->left,input,a);
    ceil(rootnode->right,input,a);
}

int findCeil(Node* root, int input) {
    // Your code here
    int d=INT_MAX;
    ceil(root,input,d);
    if(d==INT_MAX)
    return -1;
    return d;
}
