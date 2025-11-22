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

Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key< root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main(){
    Node* root = nullptr;
    int keys[] = {4, 2, 6, 1, 3, 5, 7};
    for(int key : keys){
        root = insert(root, key);
    }

    cout << "Root of the BST is: " << root->data << endl;
    cout << "Left child of root is: " << root->left->data << endl;
    cout << "Right child of root is: " << root->right->data << endl;

    return 0;
}