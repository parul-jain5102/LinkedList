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
    Student(string n, int i)
    {
        name = n;
        id = i;
        link = NULL;
    }
};
void Print(Student *head)
{
    while (head != NULL)
    {
        cout << head->name << " " << head->id << "--->";
        head = head->link;
    }
}
// void deleteItem(string key, Student **head) delete head  using double pointer
// {
//     Student *prev = NULL, *curr = *head;  // *head=s1
//     while (curr != NULL)
//     {
//         if (curr->name == key)
//         {
//             if (prev)
//             {
//                 prev->link = curr->link;
//             }
//             else
//             {
//                 *head=(*head)->link;
//             }
//             curr->link = NULL;
//             delete curr;
//             cout << key << " Deleted" << endl;
//             return;
//         }
//         prev = curr;
//         curr = curr->link;
//     }
//     cout << "Element not Found" << endl;
// }
void deleteItem(string key, Student * &head) //delete head without using double pointer
{
    Student *prev = NULL, *curr = head;  // *head=s1
    while (curr != NULL)
    {
        if (curr->name == key)
        {
            if (prev)
            {
                prev->link = curr->link;
            }
            else
            {
                head=(head)->link;
            }
            curr->link = NULL;
            delete curr;
            cout << key << " Deleted" << endl;
            return;
        }
        prev = curr;
        curr = curr->link;
    }
    cout << "Element not Found" << endl;
}
int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Student *s1 = new Student("Shubham", 1);
    Student *s2 = new Student("Aditi", 3);
    Student *s3 = new Student("Gaurav", 6);
    // (*s1).link=s2;
    s1->link = s2;
    s2->link = s3;
    Print(s1);
    cout << endl;
    // deleteItem("Aditi", &s1);
    deleteItem("Shubham", s1);
    Print(s1);

    return 0;
}