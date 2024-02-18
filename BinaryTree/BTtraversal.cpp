#include<iostream>
#include "queue"
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

class BinaryTreeTraversal{
    public:
    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node *root){
        if(root==NULL) return;
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
    void postorder(node *root){
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }

    void LevelOrder(node *root){
        if(root==NULL) return;
        
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node *node=q.front();
            q.pop();
            if(node!=NULL){
                cout<<node->data<<" ";
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            else if(!q.empty()) q.push(NULL);
        }
    }

    int sumAtkthNode(node *root,int k){
        if(root==NULL) return -1;
        
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        int sum=0;
        int level=0;

        while(!q.empty()){
            node *node=q.front();
            q.pop();
            if(node!=NULL){
                if(level==k) sum+=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } 
            else if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
        return sum;
    }

    int sumofAllnodes(node *root){
        if(root==NULL) return 0;
        return sumofAllnodes(root->left)+sumofAllnodes(root->right)+root->data;
    }

    int NoofNodes(node *root){
        if(root==NULL) return 0;
        return NoofNodes(root->left)+NoofNodes(root->right)+1;
    }
};

int main(){
    BinaryTreeTraversal BT1;
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    BT1.inorder(root);
    cout<<endl;
    BT1.postorder(root);
    cout<<endl;
    BT1.preorder(root);
    cout<<endl;
    BT1.LevelOrder(root);
    cout<<endl;
    cout<<BT1.sumAtkthNode(root,0);
    cout<<endl;
    cout<<BT1.sumofAllnodes(root);
    cout<<endl;
    cout<<BT1.NoofNodes(root);
}