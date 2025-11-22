#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

int sizeDoubly(Node* head){
    int count = 0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}