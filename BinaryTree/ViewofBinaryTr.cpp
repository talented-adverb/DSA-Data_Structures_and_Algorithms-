#include<iostream>
#include"queue"
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class ViewofBinaryTr{
    public:

    void leftView(node *root){
        if(root==NULL) return;
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                node*curr=q.front();
                q.pop();
                if(i==0) cout<<curr->data<<" ";
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }

    }

    void rightView(node *root){
        if(root==NULL) return;
        queue<node *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                node *curr=q.front();
                q.pop();
                if(i==n-1) cout<<curr->data<<" ";
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL)  q.push(curr->right);
            }
        }

    }
};

int main(){
    ViewofBinaryTr B1;
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->right=new node(3);
    root->right->right=new node(6);
    root->right->left=new node(5);
    root->right->left->left=new node(7);
    B1.leftView(root);
    cout<<endl;
    B1.rightView(root);
}