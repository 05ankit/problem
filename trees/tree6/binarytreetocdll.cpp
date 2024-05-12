class Solution
{
  public:
    Node *head=NULL;
    Node *tail=NULL;
    void bTreeToList(Node* rootnode)
    {
        if(rootnode==NULL)
        {
        return ;
        }
        bTreeToList(rootnode->left);
        if(head==NULL)
        {
            head=rootnode;
            tail=rootnode;
        }
        else
        {
        tail->right=rootnode;
        rootnode->left=tail;
        tail=rootnode;
        }
        bTreeToList(rootnode->right);
    }
    Node *bTreeToCList(Node *root)
    {
       bTreeToList(root);
       head->left=tail;
       tail->right=head;
       return head ;
        
    }
};
