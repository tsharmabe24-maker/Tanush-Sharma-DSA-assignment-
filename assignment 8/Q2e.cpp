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

Node* inorderPredecessor(Node* root, Node* target){
    Node* pred = NULL;
    while(root){
        if(target->data > root->data){
            pred = root;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return pred;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* target = root->right; 
    Node* pred = inorderPredecessor(root, target);
    if(pred)
        cout << "Inorder Predecessor of " << target->data << " is " << pred->data << endl;
    else
        cout << "Inorder Predecessor of " << target->data << " does not exist" << endl;

    return 0;
}