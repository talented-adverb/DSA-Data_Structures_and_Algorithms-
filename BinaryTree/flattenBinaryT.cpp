#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        data=data;
        left=NULL;
        right=NULL;
    }
};

class flattenBinaryTree{
    public:
    void flatten(node *root){
        if(root->left!=NULL) flatten(root->left);
        node *temp=root->right;
        root->right=root->left; 
        root->left=NULL;
        node *t=root->right;
        while(t->right!=NULL){
            t->right;
        }
    }
};

int main(){

} 