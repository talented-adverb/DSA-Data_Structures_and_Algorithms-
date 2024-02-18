#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;  
    node(int x){
        data=x;
        next=NULL;
    }
}*top; 

void init(){
    top=NULL;
}

void push(int x){
    struct node *newnode=new node(x);
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    if(top==NULL){
        cout<<"UNDERFLOW\n";
        return;
    }
    else{
        top=top->next;
    }
}

void display(){
    if(top==NULL){
        cout<<"UNDERLFOW\n";
        return;
    }
    else{
        node *temp=top;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<"\n";
    }
}

int main(){
    init();
    push(1);
    push(2);
    push(4);
    push(5);
    display();
    pop();
    display();
}