int getMiddle(Node *head)
{
   // Your code here
   Node *slow=head,*fast=head->next;
   int cnt=1,cnthead=1;
   while(head)
   {
       cnthead++;
       head=head->next;
   }
   while(fast && fast->next)
   {
       slow=slow->next;
       fast=fast->next->next;
       cnt++;
   }
   if(cnthead%2==0)
   {
        //  return slow->next->data;
         return slow->data;
       
   }
    else
    {
        // return slow->data;
        return slow->next->data;
    }
   
   
}
