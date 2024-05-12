class Solution
{
    public:
    vector<int> merge(Node *rootnode1, Node *rootnode2)
    {
       //Your code here
       stack<Node*>stack1,stack2;
       vector<int> answer;
       stack1.push(rootnode1);
       stack2.push(rootnode2);
       Node *t1,*t2;
           t1=stack1.top();
           t2=stack2.top();
        while(t1->left!=NULL)
           {
               stack1.push(t1->left);
               t1=t1->left;
           }
           while(t2->left!=NULL)
           {
               stack2.push(t2->left);
               t2=t2->left;
           }
       while((!stack1.empty())&&(!stack2.empty()))
       {
           t1=stack1.top();
           t2=stack2.top();
          
           if(t1->data<t2->data)
           {
               answer.push_back(t1->data);
               stack1.pop();
               if(t1->right!=NULL)
               {
               stack1.push(t1->right);
               t1=t1->right;
               while(t1->left!=NULL)
               {
                   stack1.push(t1->left);
                   t1=t1->left;
               }
               }
           }
           else
           {
               answer.push_back(t2->data);
               stack2.pop();
               if(t2->right!=NULL)
               {
                   stack2.push(t2->right);
                   t2=t2->right;
                   while(t2->left!=NULL)
                   {
                       stack2.push(t2->left);
                       t2=t2->left;
                   }
               }
           
           }
        
       }
       while(!stack1.empty())
       {
           t1=stack1.top();
           answer.push_back(t1->data);
           stack1.pop();
           if(t1->right!=NULL)
           {
               stack1.push(t1->right);
               t1=t1->right;
               while(t1->left!=NULL)
               {
                   stack1.push(t1->left);
                   t1=t1->left;
               }
           }
       }
        while(!stack2.empty())
       {
           t2=stack2.top();
           answer.push_back(t2->data);
           stack2.pop();
           if(t2->right!=NULL)
           {
               stack2.push(t2->right);
               t2=t2->right;
               while(t2->left!=NULL)
               {
                   stack2.push(t2->left);
                   t2=t2->left;
               }
           }
       }
       return answer;
    }
};
