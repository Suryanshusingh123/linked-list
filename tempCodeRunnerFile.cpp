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
node* merge(node*head1,node*head2)
{
   node*p1=head1;
   node*p2=head2;
   node* dummynode=new node(-1);
   node*p3=dummynode;

   while(p1!=NULL&&p2!=NULL)
   {
       if(p1->data<p2->data)
       {
           p3->next=p1;
           p1=p1->next;
           p3=p3->next;
       }
       else{
           p3->next=p2;
           p2=p2->next;
           p3=p3->next;
       }
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
node*mergesort(node*head)
{
   if(head==NULL||head->next==NULL)
   {
       return head;
   }
   node*mid=midpoint(head);
   node*half1=head;
   node*half2=mid;
   half1=mergesort(half1);
   half2=mergesort(half2);

   node*finalhead=merge(half1,half2);
   return finalhead; 
}
int main()
{
    node* head=takeinput2();
    head = mergesort(head);
	print(head);
  