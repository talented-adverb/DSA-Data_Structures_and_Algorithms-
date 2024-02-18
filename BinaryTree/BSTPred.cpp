#include<iostream>
using namespace std;

class node{
    public:
    
    int data;
    node* left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

class BST{
    public:
    
    node *TreeMax(node *x){
        while(x->right!=NULL){
            x=x->right;
        }
        return x;
    }

    node *BSTPred(node *root,node *x){//rightmost node of the left subtree
        if(x->left!=NULL) return TreeMax(x->left);
        node *Pred=NULL;
        while(true){
            if(x->data>root->data){
                Pred=root;
                root=root->right;
            }
            else if(x->data<root->data) root=root->left;
            else break;
        }
        return Pred;
    }

};

int main(){
    node *root=new node(15);
    root->left=new node(6);
    root->left->left=new node(3);
    root->left->left->right=new node(4);
    root->right=new node(18);
    root->left->right=new node(7);
    root->left->right->right=new node(13);
    root->left->right->right->left=new node(9);
    BST b;
    cout<<b.BSTPred(root->left->left->right,root)->data;
}