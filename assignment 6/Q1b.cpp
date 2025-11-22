#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int x){
    Node* n = new Node;
    n->data = x;
    n->next = n->prev = nullptr;
    return n;
}

void display(Node* head){
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Doubly Circular Linked List: ";
    while(head){
        cout<<head->data<<" ";
        head = head->next;
        if(head->next == nullptr) break;
    }
    cout<<endl;
}

void insertBegin(Node*& head, int x){
    Node* n = createNode(x);
    if(!head) {
        head = n;
        return;
    }
    else{
        n->next = head;
        n->prev = n;
        head = n;
    }
}

void insertEnd(Node*& head, int x){
    Node* n = createNode(x);
    if(!head) {
        head = n;
        return;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void insertAfter(Node* head, int key, int x){
    while(head && head->data != key){
        head = head->next;
    }
    if(!head){
        cout<<"Key not found"<<endl;
        return;
    }
    Node* n = createNode(x);
    n->next = head->next;
    n->prev = head;
    if(head->next){
        head->next->prev = n;
    }
    head->next = n;
}

void insertBefore(Node*& head, int key, int x) {
    if (!head) { cout << "List empty\n"; return; }

    if (head->data == key) {
        insertBegin(head, x);
        return;
    }

    Node* p = head;
    while (p && p->data != key)
        p = p->next;

    if (!p) {
        cout << "Key not found\n";
        return;
    }

    Node* n = createNode(x);
    n->next = p;
    n->prev = p->prev;
    p->prev->next = n;
    p->prev = n;
}

void deleteNode(Node*& head, int key){
    if(!head){
        cout<<"List empty\n";
        return;
    }
    Node* temp = head;
    while(temp && temp->data != key){
        temp = temp->next;
    }
    if(!temp){
        cout<<"Key not found"<<endl;
        return;
    }
    if(temp == head){
        head = head->next;
    }
    if(temp->next){
        temp->next->prev = temp->prev;
    }
    if(temp->prev){
        temp->prev->next = temp->next;
    }
    delete temp;
}

void search(Node* head, int key){
    int pos = 1;
    while(head){
        if(head->data == key){
            cout<<"Found at position "<<pos<<endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout<<"Key not found"<<endl;
}

int main() {
    Node* head = NULL;
    int ch, key, val;

    while (true) {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> val; insertBegin(head, val); break;
            case 2: cin >> val; insertEnd(head, val); break;
            case 3: cin >> key >> val; insertAfter(head, key, val); break;
            case 4: cin >> key >> val; insertBefore(head, key, val); break;
            case 5: cin >> key; deleteNode(head, key); break;
            case 6: cin >> key; search(head, key); break;
            case 7: display(head); break;
            case 8: return 0;
        }
    }
}