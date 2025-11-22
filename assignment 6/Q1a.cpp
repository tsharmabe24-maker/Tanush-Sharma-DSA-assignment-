#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int x){
    Node* n = new Node;
    n->data = x;
    n->next = nullptr;
    return n;
}

void display(Node* tail){
    if(!tail){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* p = tail->next;
    cout<<"Circular Linked List: ";
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=tail->next);
    cout<<endl;
}

void insertBegin(Node*& tail, int x){
    Node* n = createNode(x);
    if(!tail){
        tail = n;
        n->next = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
    }
}

void insertEnd(Node*&tail, int x){
    Node* n = createNode(x);
    if(!tail){
        tail = n;
        n->next = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void insertAfter(Node* tail,int key, int x){
    if(!tail){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* p = tail->next;
    do{
        if(p->data == key){
            Node* n = createNode(x);
            n->next = p->next;
            p->next = n;
            if(p == tail){
                tail = n;
            }
            return;
        }
        p = p->next;
    }while(p != tail->next);
    cout<<"Key not found"<<endl;
}

void insertBefore(Node*& tail, int key, int x){
    if(!tail){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* p = tail->next;
    Node* prev = tail;
    do{
        if(p->data == key){
            Node* n = createNode(x);
            n->next = p;
            prev->next = n;
            if(p == tail->next){
                tail->next = n;
            }
            return;
        }
        prev = p;
        p = p->next;
    }while(p != tail->next);
    cout<<"Key not found"<<endl;
}

void deleteNode(Node*& tail, int key){
    if(!tail) {
        cout<<"List empty\n";
        return;
    }
    Node* prev = tail;
    Node* p = tail->next;
    do{
        if(p->data==key){
            if(p==prev){
                delete p;
                tail = NULL;
                return;
            }
            prev->next = p->next;
            if(p==tail){
                tail = prev;
            }
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }while(p!=tail->next);
    cout<<"Key not found"<<endl;
}

void Search(Node* tail, int key){
    if(!tail){
        cout<<"List empty\n";
        return;
    }
    Node* p = tail->next;
    int pos = 1;
    do{
        if(p->data==key){
            cout<<"Found at position "<<pos<<endl;
            return;
        }
        p = p->next;
        pos++;
    }while(p!=tail->next);
    cout<<"Key not found"<<endl;
}

int main(){
    Node* tail = nullptr;
    int ch, key, val;
    while(true){
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cin >> ch;

        switch(ch){
            case 1: cin>>val; insertBegin(tail, val); break;
            case 2: cin>>val; insertEnd(tail, val); break; 
            case 3: cin>>key>>val; insertAfter(tail, key, val); break;
            case 4: cin>>key>>val; insertBefore(tail, key, val); break;
            case 5: cin>>key; deleteNode(tail, key); break; 
            case 6: cin>>key; Search(tail, key); break;
            case 7: display(tail); break;
            case 8: return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
}