#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node* inorderSuccessor(Node* root, Node* target){
    Node* succ = NULL;
    while(root){
        if(target->data < root-> data){
            succ = root;
            root = root->left;
        }else root = root->right;
    }
    return succ;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* target = root->left; 
    Node* succ = inorderSuccessor(root, target);
    if(succ)
        cout << "Inorder Successor of " << target->data << " is " << succ->data << endl;
    else
        cout << "Inorder Successor of " << target->data << " does not exist" << endl;

    return 0;
}