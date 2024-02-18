#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int x=0){
        data=x;
        next=NULL;
    }
};

class CircularLinkedlist{

    public:
    
    void insert_beg(int x,node **head){
        node *newnode=new node(x);
        if(head==NULL){
            newnode->next=*head;
            *head=newnode;
        }
        else{
            node *temp=*head;
            while(temp->next!=*head) temp=temp->next;
            temp->next=newnode;
            newnode->next=*head;
            *head=newnode;
        }
    }

    void insert_end(int x,node **head){
        node *newnode=new node(x);
        if(!*head){
            newnode->next=*head;
            *head=newnode;
        }
        else{
            node *temp=*head;
            while(temp->next!=*head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=*head;
        }
    }

    void display(node *head){
        if(head==NULL){ 
            cout<<"Empty list"; 
            return;
        }
        else{
            node *temp=head;
            while(temp->next!=head){
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
            cout<<temp->data<<"\n";
        }
    }

    void insert_aft_spec(node **head,int posvalue){
        node *newnode=new node();
        if(!*head){
            *head=newnode;
            newnode->next=*head;
        }
        else{
            node *temp=*head;
            while(temp->next!=*head && temp->data!=posvalue){
                temp=temp->next;
            }
            if(temp->data!=posvalue) cout<<"node not found";
            else {
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
    }

    void search(node *head,int num){
        if(head==NULL){
            cout<<"Empty list\n";
            return;
        }
        else{
            node *temp=head;
            while(temp->next!=head && temp->data!=num){
                temp=temp->next;
            }
            if(temp->data==num) cout<<"Element found\n";
            else cout<<"Element not found\n"; 
        }
    }
};

int main(){
    CircularLinkedlist c1;
    node *head=new node(1);
    node *num1=new node(2);
    node *num2=new node(3);
    node *num3=new node(4);
    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=head;
    c1.display(head);
    // c1.insert_beg(10,&head);
    // c1.display(head);
    // c1.insert_end(20,&head);
    // c1.display(head);
    // c1.search(head,20);
    c1.insert_aft_spec(&head,3);
    c1.display(head);
}
