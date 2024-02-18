#include<iostream>
using namespace std;
#define INT_MIN 0
#define INT_MAX 100

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int x){
        data=x;
        left= nullptr;
        right=nullptr; 
    }
};

class BST{
    public:
    node* constructBST(int preorder[],int *preorderIdx,int key,int min,int max,int n){
        if(*preorderIdx>=n) return NULL;
        node *root=NULL;
        if(key>min && key<max){
            root=new node(key);
            *preorderIdx=*preorderIdx+1;
            if(*preorderIdx<n) root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
            if(*preorderIdx<n) root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
        return root;
    }
        void preorder(node *root) {
            if(root==NULL) return;
            cout<<root->data<<"->";
            preorder(root->left);
            preorder(root->right);
        }
};

int main(){
    BST B1;
    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;
    node *root=B1.constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    B1.preorder(root);
}
