#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

int sizeCircular(Node*tail){
    if(tail==NULL) return 0;

    int count = 1;
    Node* temp = tail->next;
     while(temp!=tail){
        count++;
        temp=temp->next;
    }
    return count;
}