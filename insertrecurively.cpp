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
node* insertrec(int data,int i,node* head)
{
    node*temp=head;
   if(head==NULL)
   {
       return head;
   }
   if(i==0)
   {
       node*newnode=new node(data);
       newnode->next=temp;
       head=newnode;
       return head;
   }
   node* x=insertrec(data,i-1,head->next);
   head->next=x;
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

int main()
{
    node* head=takeinput();
    print(head);
    int i,data;
    cin>>i>>data;
    head=insertrec(data,i,head);
    print(head);

}