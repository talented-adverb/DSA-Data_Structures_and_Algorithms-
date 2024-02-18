#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node *parent;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class BST{
    
    public:
    
    node *insertion(node *root,int val){
        node *z=new node(val);
        z->left=z->right=z->parent=NULL;
        node *x=root;
        node *y=NULL;
        while(x!=NULL){
            y=x;
            if(z->data<x->data){
                x=x->left;
            }
            else x=x->right;
        }
        if(y==NULL){
            root=z;
            return root;
        }
        z->parent=y;
        if(z->data<y->data) y->left=z;
        else y->right=z;
        return y;
    }

    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
    
};

int main(){
    BST B1;
    node *root=NULL;
    root=B1.insertion(root,6);
    B1.insertion(root,3);
    B1.insertion(root,4);
    B1.preorder(root);
}