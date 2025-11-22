#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void displayCircular(Node* head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<head->data;
    cout<<endl;
}