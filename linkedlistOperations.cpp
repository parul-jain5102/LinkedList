#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int id;
    Student *link;
    Student() {}
    Student(string n, int i)
    {
        name = n;
        id = i;
        link = NULL;
    }
};
class LinkedList
{
public:
    Student *head;
    LinkedList()
    {
        this->head = NULL;
    }
    void InsertAtBeg(Student);
    void InsertAtPos(int, Student);
    void DeleteStudent(string);
    void Print();
    void Reverse();
    void RecReverse();
    void VectorToList(vector<pair<string, int>>);
};
void LinkedList::VectorToList(vector<pair<string, int>> v)
{
    for(auto x:v)
    {
        Student *temp=new Student();
        temp->name=x.first;
        temp->id=x.second;
        InsertAtBeg(*temp);
    }

}
void LinkedList::InsertAtBeg(Student t)
{
    Student *temp = new Student();
    temp->name = t.name;
    temp->id = t.id;
    temp->link = head;
    head = temp;
}
Student *RevUtil(Student *temp,Student * &HeadOfReverseList)
{
    if(temp->link==NULL)
    {  
        HeadOfReverseList=temp;
        return temp;

    }
   Student *LastOfReverse=RevUtil(temp->link,HeadOfReverseList);
   temp->link=NULL;
   LastOfReverse->link=temp;
   return temp;
}
void LinkedList::RecReverse()
{    
    Student *HeadOfReverseList;
    Student *t=RevUtil(head,HeadOfReverseList); // it will return the last element of the reversed list
    head=HeadOfReverseList;
    return;
}
void LinkedList::Reverse()
{
    Student *curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    cout<<"Successfully reversed"<<endl;
}

void LinkedList::InsertAtPos(int pos, Student s)
{
    // if (pos == 1)
    // {
    //     InsertAtBeg(s);
    //     return;
    // }
    int cnt = 1;
    Student *temp = head, *prev = NULL;
    while (temp)
    {
        if (cnt == pos)
        {
            Student *t = new Student(s.name, s.id);
            t->link = temp;
            if (prev) // that means if previous exists
            {
                prev->link = t;
            }
            else //means previous does not exist(insert at pos 1)
            {
                head = t;
            }
            cout << "Element Successfully added" << endl;
            return;
        }
        prev = temp;
        temp = temp->link;
        cnt++;
    }
    if (pos == cnt)
    {
        Student *t = new Student(s.name, s.id);
        t->link = NULL;
        if (prev)
        {
            prev->link = t;
        }
        else
        {
            head = t;
        }
        cout << "Element Successfully added" << endl;
        return;
    }
    cout << "Position exceeded the linked list" << endl;
}
void LinkedList::Print()
{
    Student *temp = head;
    while (temp)
    {
        cout << temp->name << " " << temp->id << "--->";
        temp = temp->link;
    }
    cout << endl;
}
void LinkedList::DeleteStudent(string name)
{
    Student *temp=head,*prev=NULL;
    while(temp)
    {
        if(temp->name==name)
        {
            if(prev)
            {
                prev->link=temp->link;
            }
            else
            {
                head=temp->link;

            }
            temp->link=NULL;
            delete temp;
            cout<<endl;
            cout<<name<<" successfully deleted"<<endl;
            return;
        }
        prev=temp;
        temp=temp->link;
    }
    cout<<name<<" not found"<<endl;
}
int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    LinkedList *LL = new LinkedList();
    Student s1("Shubham", 12), s2("Shailly", 67), s3("Arnav", 89);
    LL->InsertAtBeg(s1);
    LL->InsertAtBeg(s2);
    LL->InsertAtBeg(s3);
    Student s4("Stuti", 78);
    LL->InsertAtPos(4,s4);
    LL->Print();
    // LL->RecReverse();
    // LL->Print();
    // LL->DeleteStudent("Shailly");
    // LL->Print();
     LL->Reverse();
    LL->Print();

    // (*LL).DeleteStudent("shailly");
    // LL->DeleteStudent("sahil");

    return 0;
}