
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head=NULL;

void insert(int data){
 
    Node* newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    
    if(head==NULL)
    {
       head= newNode;
       return;
    }
       Node* temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=newNode;
}
void display(){
    Node* temp=head;
    if(temp==NULL){
        cout<<"\nlist is empty\n";
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reverseList(){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    
    while(curr!=NULL){
       next= curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
    }
    head=prev;
    cout<<"linkedlist reversed\n";
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    cout << "linked list:\n";
    display();
    reverseList();
    display();
 return 0;
}
