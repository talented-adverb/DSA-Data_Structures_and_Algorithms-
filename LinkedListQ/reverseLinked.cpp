#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int x){
        this->data=x;
        this->next=NULL;
    }
};

class Linkedlist{
    public:
    node *temp;
    
    void insert_beg(node *&head,int value){
        node *newnode=new node(value);
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }

    void reverse(node *&head){
        if(head==NULL) return;
        temp=NULL;
        node *current=head;
        while(current!=NULL){
            node *p=current->next;
            current->next=temp;
            temp=current;
            current=p;
        }
        head=temp;
    }

    node* reverseRecursive(node* &head){
        if(head==NULL || head->next==NULL) return head;
        
        node *newhead=reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }

    void transverse(node *head){
        node* temp=head;
        if(head==NULL) cout<<"Empty linked list\n";
        else{
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Linkedlist L1;
    node *head=new node(1);
    node *second=new node(2);
    node *third=new node(3);
    head->next=second;
    second->next=third;
    L1.insert_beg(head,50);
    L1.transverse(head);
    head=L1.reverseRecursive(head);
    L1.transverse(head);
}