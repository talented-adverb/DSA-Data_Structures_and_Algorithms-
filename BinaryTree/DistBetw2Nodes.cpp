#include<iostream>
using namespace std;

//STRATEGY
/*
    Find the LCA
    Find the Distance of n1(->d1) and n2(->d2) from LCA
    return d1+d2
*/

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

class DistBetw2Nodes{
    public:
    node *LCA(node *root,int n1,int n2){
        if(root==NULL) return NULL;
        if(root->data==n1 || root->data==n2) return root;

        node* left=LCA(root->left,n1,n2);
        node *right=LCA(root->right,n1,n2);

        if(left!=NULL && right!=NULL) return root;
        if(right==NULL && left==NULL) return NULL;
        if(left!=NULL) return LCA(root->left,n1,n2);
        return LCA(root->right,n1,n2);
    }

    int finddist(node *lca,int k,int dist){
        if(lca==NULL) return -1;
        if(lca->data==k) return dist;
        int left=finddist(lca->left,k,dist+1);
        if(left!=-1) return left;
        return finddist(lca->right,k,dist+1);

    }

    int distBtwNodes(node *root,int n1,int n2){
        node *lca=LCA(root,n1,n2);
        int d1=finddist(lca,n1,0);
        int d2=finddist(lca,n2,0);
        return d1+d2;
    }
};

int main(){
    DistBetw2Nodes B1;
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    cout<<B1.distBtwNodes(root,5,1);
}