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

void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node *deletenodeRec(node *head, int i) {
	 if(head == NULL){
        return head;
    }
    if(i == 0){
        node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    node* x = deletenodeRec(head -> next, i - 1);
    head -> next = x;
    return head;
}

int main()
{
    node* head=takeinput();
    print(head);
    int i;
    cin>>i;
    head = deletenodeRec(head, i);
	print(head);
}