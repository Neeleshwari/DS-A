Node* createNode(int data)
{
    struct Node *newnode = new Node(data);
    return(newnode);
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *prev,*temp=NULL,*newn,*head=NULL,*curhead=NULL;
    
    for(int i=0;i<n;i++)
    {
        prev = NULL;

        for(int j=0;j<n;j++)
        {
            newn = createNode(mat[i][j]);
            if (head == NULL)
                head = newn;
            
            if ( curhead == NULL)
                curhead = newn;
            
            if (prev != NULL)
                prev->right = newn;
                
            if (i>0 && temp!=NULL)
            {
                temp->down = newn;
                temp = temp->right;
            }
            prev = newn;
        }
        prev->right = NULL;
        
        temp = curhead;
        curhead = NULL;
    }
    while ( temp != NULL )
    {
        temp->down = NULL;
        temp = temp->right;
    }
    return(head);
}
