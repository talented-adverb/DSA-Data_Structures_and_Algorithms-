//DOUBT

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

class LinkedList{
    public:

    node* reverseKnode(node *&head, int k){
        node * nextptr;
        node * prevptr=NULL;
        node * currptr=head;
        int count=0;
        while(currptr!=NULL && count<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        if(nextptr!=NULL){
            head->next=reverseKnode(nextptr,k);
        }
        return prevptr;
    }
};

int main(){

}