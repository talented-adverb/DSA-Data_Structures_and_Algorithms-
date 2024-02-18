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

class CircularDoublyLL{
    public:
    
    void insert_beg(node *&head,int num){
        node *nN=new node(num);
        if(head==NULL) nN->next=nN->prev=nN;
        else{
            nN->next=head;
            nN->prev=head->prev;
            head->prev->next=nN;
            head=nN;
        } 
    }

    void insert_end(node *&head,int num){
        node *nN=new node(num);
        if(head==NULL) nN->next=nN->prev=nN;
        else{
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            nN->next=head;
            nN->prev=temp;
            head->prev=nN;
            temp->next=nN;
        }
    }

    void insert_spec_node(node *&head,int nodeval,int num){
        node *nN=new node(num);
        if(head==NULL) nN->next=nN->prev=nN;
        else {
            node *temp=head;
            while(temp!=head && temp->data!=nodeval){
                temp=temp->next;
            }
            nN->next=temp->next;
            nN->prev=temp;
            temp->next->prev=nN;
            temp->next=nN;
        }
    }

    void delete_beg(node *&head){
        if(head==NULL) cout<<"Empty";
        else{
            node*temp=head;
            if(temp->next==head) head=NULL;
            else{
                head->next->prev=head->prev;
                head->prev->next=head->next;
                head=head->next;
            }
        free(temp);
        }
    }

    void delete_end(node *&head){
        if(head==NULL) cout<<"Empty";
        else{
            node *temp=head;
            while(temp->next!=head) temp=temp->next;
            if(temp==head) head=NULL;
            else{
                temp->prev->next=temp->next;
                head->prev=temp->prev;
            }
        free(temp);
        }
    }

    void del_spec(node *&head,int val){
        if(head==NULL) cout<<"Empty";
        else{
            node *temp=head;
            while(temp->next!=head && temp->data!=val){
                temp=temp->next;
            }
            if(temp->data!=val){
                cout<<"Element not found\n";
                return;
            }
            else if(temp==head) delete_beg(head);
            else if(temp->next==head) delete_end(head);
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            free(temp);
        }
    }

    void display(node *head){
        node *temp=head;
        while(temp->next!=head){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }

    void display2(node *head){
        node *temp=head;
        while(temp->next!=head){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<temp->next->data;
        cout<<endl;
    }

    void search(node *head,int searchval){
        node *temp=head;
        while(temp->next!=head && temp->data!=searchval){
            temp=temp->next;
        }
        if(temp->data!=searchval) cout<<"Node not found\n";
        else cout<<"Node found\n";
    }

    void size(node *head){
        node *temp=head;
        int count=0;
        while(temp->next!=head){
            temp=temp->next;
            count++;
        }
        count++;
        cout<<"Size of CircularLinkedList:"<<count;
    }
};

int main(){
    CircularDoublyLL C1;
    node *head=new node(1);
    node *Second=new node(2);
    node *third=new node(3);
    head->next=Second;
    head->prev=third;
    Second->next=third;
    Second->prev=head;
    third->next=head;
    third->prev=Second;
    C1.insert_beg(head,2);
    C1.display(head);
    C1.insert_end(head,3);
    C1.display(head);
    C1.insert_spec_node(head,3,5); 
    C1.display(head);
    // C1.delete_beg(head); 
    // C1.display(head);
    // C1.delete_end(head);
    // C1.display(head);
    C1.del_spec(head,5);
    C1.display(head);
    C1.search(head,3);
    C1.display2(head);
    C1.size(head);
}