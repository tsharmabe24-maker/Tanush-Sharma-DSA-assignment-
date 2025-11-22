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

Node* searchRec(Node* root, int key){
    if(!root || root->data == key) return root;
    if(key<root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key){
    while(root){
        if(root->data == key) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int key = 5;
    Node* resultRec = searchRec(root, key);
    if(resultRec)
        cout << "Recursive Search: Found " << resultRec->data << endl;
    else
        cout << "Recursive Search: " << key << " not found" << endl;

    Node* resultIter = searchIter(root, key);
    if(resultIter)
        cout << "Iterative Search: Found " << resultIter->data << endl;
    else
        cout << "Iterative Search: " << key << " not found" << endl;

    return 0;
}