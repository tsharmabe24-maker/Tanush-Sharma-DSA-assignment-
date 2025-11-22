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

Node* findMin(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(!root) return nullptr;
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int key = 6;
    root = deleteNode(root, key);
    cout << "Node with key " << key << " deleted from the BST." << endl;

    return 0;
}