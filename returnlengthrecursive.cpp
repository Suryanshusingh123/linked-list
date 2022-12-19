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
int reclength(node*head)
{
    if(head==NULL)
    {
        return 0;
    }
    return reclength(head->next)+1;
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
    node* head=takeinput2();
    print(head);
    cout<<endl<<reclength(head);
}