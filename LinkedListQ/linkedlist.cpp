#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data=0;
        next=NULL;
    }

    Node(int n){
        this->data=n;
        this->next=NULL;
    }
};

class Linkedlist{
    public:

    Node *head=NULL;
    
    void insert_beg(int value){
        Node *newnode=new Node();
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }
    
    void transverse(){
        Node* temp=head;
        if(head==NULL) cout<<"Empty linked list\n";
        else{
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }

    void searchelement(int x){
        Node *current=head;
        if(head==NULL){
            cout<<"Empty list\n";
            return;
        }
        // while(current!=NULL){
        //     if(current->data==x){
        //         cout<<"element found\n";
        //         return;
        //     }
        //     current=current->next;
        // }
        // cout<<"element not found\n";
        while(current!=NULL && current->data!=x){
            current=current->next;
        }
        if(current==NULL) cout<<"Element not found\n";
        else cout<<"Element found\n";
    }

    void insert_end(int value){
        Node *newnode=new Node(value);
        if(head==NULL){
            head=newnode;
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }

    void insert_aftspec(int exist_val,int new_val){
        
        Node *newnode=new Node(new_val);
        Node *temp=head;
        if(head==NULL) 
        {
            head=newnode;
            return;
        }
        while(temp!=NULL && temp->data!=exist_val){
            temp=temp->next;
        }
        if(temp==NULL) cout<<"Existing value not found so Node not inserted";
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

    void insert_atspec_pos(int pos,int value){
        Node *q=head;
        if(pos<0){
            cout<<"invalid position";
            return;
        }
        for(int i=0;i<pos-1;i++){
            q=q->next;
            if(q==NULL){
                cout<<"Invalid position\n";
                return;
            }
        }
        if(head==NULL){
            cout<<"Empty LL";
            return ;
        }
        Node *newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        newnode->next=q->next;
        q->next=newnode;
    }

    void del_spec_node(int num){
        Node *newnode=new Node(num);
        if(head==NULL){
            cout<<"Empty list";
            return ;
        }
        else{
            Node *temp=head;
            Node *prev;
            while(temp!=NULL && temp->data!=num){
                prev=temp;
                temp=temp->next;
            }         
            if (temp==NULL) cout<<"Element not found\n";
            else if(temp->next=NULL) prev->next=NULL;
            else if(temp==head) head=head->next;
            else prev->next=temp->next;
        free(temp);
        }
    }
    
};

int main(){
    Linkedlist L1;
    // L1.transverse();
    L1.insert_beg(1);
    // L1.searchelement(1);
    L1.insert_end(3);
    L1.insert_beg(2);
    L1.insert_aftspec(2,4);
    L1.del_spec_node(2);
    L1.transverse();
}