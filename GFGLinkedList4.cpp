bool check(Node * &left,Node *right)
{
    if(right==NULL)
    {
        return 1;
    }
    if(check(left,right->next) && (right->data==left->data))
    {
        left=left->next;
        return 1;
    }
    return 0;
}

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {  Node *left=head,*right=head;
      bool ans=check(left,right);
      return ans;
        //Your code here
    }
};
