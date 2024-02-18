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

class BinaryT{
    public:
    
    void sumReplacement(node *root){
        if(root==NULL) return;

        sumReplacement(root->left);
        sumReplacement(root->right);

        if(root->left!=NULL) root->data+=root->left->data;
        if(root->right!=NULL) root->data+=root->right->data;
    }

    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){
    BinaryT B1;
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    B1.sumReplacement(root);
    B1.preorder(root);
}