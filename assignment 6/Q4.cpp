#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

bool isPallindrome(Node* head){
    if(head==NULL || head->next == NULL){
        return true;
    }
    Node*left = head;
    Node* right = head;
    while(right->next != NULL){
        right = right->next;
    }
    while(left!=right && left->prev != right){
        if(left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}