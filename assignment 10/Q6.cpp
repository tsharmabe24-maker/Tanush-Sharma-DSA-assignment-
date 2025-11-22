#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

bool checkDuplicates(Node* root,unordered_set<int>&s){
    if(!root) return false;
    if(s.count(root->data)) return true;
    s.insert(root->data);
    return checkDuplicates(root->left,s) || checkDuplicates(root->right,s);
}

bool hasDuplicates(Node* root){
    unordered_set<int> s;
    return checkDuplicates(root,s);
}

int main(){
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{2, nullptr, nullptr}; 

    if(hasDuplicates(root)){
        cout << "Tree contains duplicates." << endl;
    } else {
        cout << "No duplicates in the tree." << endl;
    }

    return 0;
}
