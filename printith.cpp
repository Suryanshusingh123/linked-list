#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next;

        node(int data)
        {
            this->data=data;
            next=NULL;
        }
};


node* takeinput()
{
    int data;
    cin>>data;
    node *head=NULL;
    while(data!=-1)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;
    }
   return head;
}      

void printi(node *head,int i)
{
    node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
        if(count==i)
        {
            cout<<temp->data;
        }
    }
}


int main()
{
    node* head=takeinput();
    int i;
    cin>>i;
    printi(head,i);
}