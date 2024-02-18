#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node *parent;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class BST{
    public:

    node* TreeMin(node *x){
        while(x->left!=NULL) x=x->left;
        return x;
    }

    node *BSTSucc(node *x,node *root){
        if(x->right!=NULL) return TreeMin(x->right);
        node *succ=NULL;
        while(true){
            if(x->data<root->data){
                succ=root;
                root=root->left;
            }
            else if(x->data>root->data) root=root->right;
            else break;
        }
        return succ;
    }
};

int main(){ 
    node *root=new node(15);
    root->left=new node(6);
    root->right=new node(18);
    root->left->right=new node(7);
    root->left->right->right=new node(13);
    root->left->right->right->left=new node(9);
    BST b;
    cout<<b.BSTSucc(root->left->right->right,root)->data;
}