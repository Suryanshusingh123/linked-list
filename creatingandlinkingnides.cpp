#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int data)
        {
            this->data=data;
            next=NULL;

        }
};
void print(node* head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
int main()
{
    int data;
   // cin>>data;
    node n1(10);
    node* head=&n1;
    node n2(20);
    node n3(30);
    node n4(40);
    node n5(50);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print(head);


}