struct Node* reverseList(struct Node *head)
    {
        struct Node *curr=head,*prev=NULL,*nex=NULL;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    head=prev;
    return head;
}
