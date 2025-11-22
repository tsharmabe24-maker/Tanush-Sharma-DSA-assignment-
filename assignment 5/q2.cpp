
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
void deleteOccurrences(int key){
    Node* current=head;
    Node* prev=NULL;
    int count=0;
    
    while (current != NULL && current->data == key) {
        Node* temp = current;
        head = current->next;
        current = head;
        delete temp;
        count++;
    }

    while (current != NULL) {
        if (current->data == key) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
            count++;
        } else {
            prev = current;
            current = current->next;
        }
    }

    cout << "Number of occurrences deleted: " << count << endl;
}

int main() {
    insert(1);
    insert(1);
    insert(2);
    insert(1);
    insert(2);
    insert(3);

    cout << "Before deletion:\n";
    display();

    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    deleteOccurrences(key);

    cout << "After deletion:\n";
    display();

    return 0;
}
