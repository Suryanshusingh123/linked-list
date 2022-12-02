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
node* deletenode(int i,node* head)
{
  //  node* newnode=new node(data);
    node*temp=head;
    int count=0;
    if(i==0)
    {
        node*a=temp->next;
        head=a;
        delete temp;
    }
    while(temp!=NULL&&count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        node *a=temp->next;
        node*b=a->next;
        temp->next=b;
        delete a;
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

int main()
{
    node* head=takeinput();
    print(head);
    int i;
    cin>>i;
    head=deletenode(i,head);
    print(head);

}