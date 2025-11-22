#include <bits/stdc++.h>
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

bool isBSTUtil(Node* root, long minv, long maxv){
    if(!root) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left, minv, root->data) && isBSTUtil(root->right, root->data, maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}