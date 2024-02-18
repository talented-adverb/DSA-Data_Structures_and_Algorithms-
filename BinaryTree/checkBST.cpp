#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    bool checkBST(node *root,node* min,node* max){
        if(root==NULL) return true;
        if(min!=NULL && root->data<=min->data) return false;
        if(max!=NULL && root->data>=max->data) return false;
        bool leftValid=checkBST(root->left,min,root);
        bool rightValid=checkBST(root->right,root,max);
        return leftValid && rightValid;
    }
};

int main(){
    BST B1; 
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(11);
    if(B1.checkBST(root,NULL,NULL)) cout<<"BST";
    else cout<<"Not a BST";
}