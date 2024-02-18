#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

class LinkedList{
    public:
    void insert_beg(node *&head,int v){
        node *newnode=new node(v);
        if(head){
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        else{
            head=newnode;
        }
    }

    void insert_end(node *&head,int v){
        node *newnode=new node(v);
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

    void insert_after(node *&head,int v,int x){
        node *newnode=new node(x);
        node *temp=head;
        if(head){
            int count=1;
            while(temp!=NULL && temp->data!=v){ //wrong
                temp=temp->next;
            }
            temp->next->prev=newnode;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
        }
        else{
            head=newnode;
        }
    }

    void display(node *head){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }

    void del_beg(node *&head){
        if(head){
            node *temp=head;
            head=head->next;
            head->prev=NULL;
            delete(temp);
        }
        else{
            cout<<"Empty Linked List\n";
        }
    }

    void del_end(node *&head){
        if(head){
            node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            if(temp==head) {
                head=NULL;
            }
            else{
                temp->prev->next=NULL;
            }
            free(temp);
        }
        else{
            cout<<"Empty Doubly Linked List\n";
        }
    }

    void del_spec(node *&head,int n){
        if(head){
            node *temp=head;
            while(temp!=NULL && temp->data!=n){
                temp=temp->next;
            }
            if(temp==NULL){
                cout<<"node with spec data value not found\n";
            }
            else if(temp==head) del_beg(head);
            else if(temp->next==NULL) del_end(head);
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
        }
        else cout<<"Empty DLL";
    }

    void size(node *head){
        node *temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        cout<<"The Size of DoublyLinkedList:"<<count;
    }

    node* reverse(node *&head){
        node *ptr1=head;
        node *ptr2=ptr1->next;
        ptr1->next=NULL;
        ptr1->prev=ptr2;
        while(ptr2!=NULL){
            ptr2->prev=ptr2->next;
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr2->prev;
        }
        head=ptr1;
        return head;
    }
};

int main(){
    LinkedList L1;
    node *head=new node(1);
    node *second=new node(2);
    node *third=new node(3);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    L1.display(head);
    L1.insert_beg(head,4);
    L1.display(head);
    L1.insert_after(head,2,5);
    L1.display(head);
    // L1.del_beg(head);
    // L1.display(head);
    // L1.del_end(head);
    // L1.display(head);
    // L1.del_spec(head,2);
    // L1.display(head);
    // L1.size(head);
    L1.reverse(head);
    L1.display(head);
}