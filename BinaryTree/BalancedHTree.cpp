#include<iostream>
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

class BalancedTr{
    public:

    int height(node *root){
        if(root==NULL) return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        return max(lh,rh)+1;
    }

    bool isBalanced(node *root){
        if(root==NULL) return true;
        if(isBalanced(root->left)==false) return false;
        if(isBalanced(root->right)==false) return false;

        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1) return true;
        else return false; 
    }

    bool isBalancedOptimized(node *root,int *height){
        int lh=0,rh=0;
        if(root==NULL) return true;
        if(isBalancedOptimized(root->left,&lh)==false) return false;
        if(isBalancedOptimized(root->right,&rh)==false) return false; 
        *height=max(lh,rh)+1;
        if(abs(lh-rh)<=1) return true;
        else return false;
    }
};

int main(){
    BalancedTr B1;
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    cout<<B1.height(root)<<endl;
    int height=0;
    if(B1.isBalancedOptimized(root,&height)) cout<<"Balanced Tree";
    else cout<<"Unbalanced Tree";
}