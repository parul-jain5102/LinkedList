struct Node* SortedMerge(struct Node* a, struct Node* b)
{   struct Node dummy;
 
    struct Node* tail = &dummy;
 
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}
