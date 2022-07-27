#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};
typedef struct TreeNode treenode;
treenode* root;

void PreOrder(treenode *root){
    if(root==NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(treenode *root) {
    if(root==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void InOrder(treenode *root) {
    if(root==NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int height(treenode* root) {
    if(root==NULL) return -1;
    int h1=1+height(root->left);
    int h2=1+height(root->right);
    return (h1>h2?h1:h2);
}

treenode * insert(treenode * root, int data) { // Insert a node whose data follows the rule of InOrder. 
    if(root==NULL){
        treenode* newnode=new treenode();
        newnode->data=data;
        newnode->left=nullptr;
        newnode->right=nullptr;
        root=newnode;
    }
    else if(root->data>data)
        root->left=insert(root->left,data);
    else if(root->data<data)
        root->right=insert(root->right,data);
    return root;
}

void LevelOrder(treenode * root) {
    if(root==NULL) return ;
    queue<treenode*> q;
    treenode* temp=root;
    q.push(root);
    while(temp!=NULL && !q.empty()){ /* Need 2 check both conditions that whether the root exists and
the queue is empty or not */
        cout << temp->data << " ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        q.pop();
        temp=q.front();
    }
}
treenode *lca(treenode *root, int v1,int v2) { /* This function returns the lowest common ancestor of 2
nodes whose values are given as v1 and v2 */
	// This tree is sorted in InOrder form.
    if(root==NULL) return root;
    if(root->data<v1 && root->data<v2) return lca(root->right,v1,v2);
    if(root->data>v1 && root->data>v2) return lca(root->left,v1,v2);
    // Here the solution is determined.
    return root; 
}

treenode* makenode(int data){
    treenode* node=new treenode();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

treenode* insertNode(treenode* root,int data,bool LEFT){
    node* p=makenode(data);
    if(root==NULL) root=p;
    node* q=root;
    if(LEFT){
        while(q->left!=NULL){
            q=q->left;
        }
        q->left=p;
    } else {
        while(q->right!=NULL){
            q=q->right;
        }
        q->right=p;
    }
    return root;
}

int countNodes(treenode* root){
    if(root==NULL) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int depth(treenode* root){
    if(root==NULL) return -1;
    return (1+depth(root->left))||(1+depth(root->right));
}

void freeTree(treenode* root){
    if(root==NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

bool checkNode(treenode* root){
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left!=NULL && root->right!=NULL) return true;
    return false;
}

bool complete(treenode* root){
    if(root==NULL) return true;
    int dL=depth(root->left);
    int dR=depth(root->right);
    if(dL<dR) return false;
    else {
        if(checkNode(root->left) && checkNode(root->right)) return true;
        else return false;
    } 
}

bool full(treenode* root){
    if(root==NULL) return true;
    int dL=depth(root->left);
    int dR=depth(root->right);
    if(dL==dR){
        if(checkNode(root->left) && checkNode(root->right)) return true;   
        else return false;
    }
}

/* Another way of implementation for the function "full":
bool full(treenode* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left && root->right) return (full(root->left)&&full(root->right));
    return false;
}
*/

void printArithmeticExp(treenode* root){ // Print the expressions that are stored in the tree.
    if(root==NULL) return;
    if(root->left!=NULL){
        cout << "(";
        printArithmeticExp(root->left);
    }
    cout << root->data << " ";
    if(root->right!=NULL){
        printArithmeticExp(root->right);
        cout << ")";
    }
}

int main(){
    return 0;
}