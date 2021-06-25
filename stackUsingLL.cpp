#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }

};
class MyStack{
    public:
    Node *head;
    MyStack()
    {
        head=NULL;
    }
    void push(int x);
    int pop();
    int peek();
    void display();
    bool isEmpty();
    void clear();

};
int MyStack::peek()
{
    if(isEmpty())
       return -1;
    return head->data;

}
void MyStack::push(int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    head=temp;
    
}
int MyStack::pop()
{   int x=-1;
    if(isEmpty())
    {
        return x;
    }
    Node *temp=head;
    head=head->next;
    temp->next=NULL;
    x=temp->data;
    delete temp;
    return x;

}
bool MyStack::isEmpty()
{
    if(head)
    {
       return false;

    }
    else
    {
        return true;
    }
     

}
void MyStack::display()
{
    Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void MyStack::clear()
{
    while(head)
    {
        pop();
    }
    cout<<"Your stack is Empty"<<endl;
}

int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
MyStack *s=new MyStack();
s->push(10);
s->push(20);
s->push(30);
s->push(40);
s->display();
cout<<s->pop()<<endl;
s->display();
cout<<s->peek();
cout<<endl;
s->clear();
s->display();
s->push(456);
s->display();


    return 0;
}