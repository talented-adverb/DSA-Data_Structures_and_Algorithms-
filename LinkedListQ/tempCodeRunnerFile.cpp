#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

class CorrectRandomPointer{
    public:
    void correctPointer(node *head){
        if(head==NULL) return;
        node *temp=head;
        while(temp!=NULL){
            if(temp->next->prev!=temp) temp->next->prev=temp;
            temp=temp->next;
        }
    }

    void display(node *head){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
    }

};

int main(){
    CorrectRandomPointer Cp1;
    node *head=new node(1);
    node *sec=new node(2);
    node *third=new node(3);
    head->next=sec;
    sec->next=head;
    sec->prev=head;
    third->prev=sec;
    Cp1.correctPointer(head);
    Cp1.display(head);
}
