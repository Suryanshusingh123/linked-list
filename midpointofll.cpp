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
node* takeinput2()
{
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;

    while(data!=-1)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
                tail->next=newnode;
                tail=newnode;
        }
    cin>>data;
    }
    return head;
}
void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node* midpoint(node*head)
{
    if(head==NULL)
    {
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
int main()
{
    node* head=takeinput2();
    print(head);
    cout<<endl;
    midpoint(head);
}