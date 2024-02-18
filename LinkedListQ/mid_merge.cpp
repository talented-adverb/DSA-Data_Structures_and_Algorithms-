#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next; 

    node(int x){
        data=x;
        next=NULL;
    }
};

class LinkedList{
    
    public:

    void insert_mid(node **head,int num){
        node *newnode=new node(10);
        if(!*head){
            newnode->next=*head;
            *head=newnode;
        }
        else{
            node *temp=*head;
            node *temp2=*head;
            while(temp2!=NULL && temp2->next!=NULL){
                temp=temp->next;
                temp2=temp2->next->next;
            }    
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

    void merge(node *head1,node *head2){
        
    }

    void transverse(node *head){
        node* temp=head;
        if(head==NULL) cout<<"Empty linked list\n";
        else{
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }

};

int main(){
    LinkedList L1;
    node *head=new node(1);
    node *num1=new node(4);
    node *num2=new node(7);
    head->next=num1;
    num1->next=num2;
    LinkedList L2;
    node *head2=new node(5);
    node *num3=new node(6);
    node *num4=new node(10);
    head2->next=num3;
    num3->next=num4;
    L1.insert_mid(&head,10);
    L1.transverse(head);
}