#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;

public:

    Linkedlist() {
        head = NULL;
    }

    void insert_end(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insert_beg(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insert_at_pos(int pos, int data) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1) {
            insert_beg(data);
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1; i++) {
            if (curr == NULL) {
                cout << "\nInvalid position\n";
                return;
            }
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "\nInvalid position\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void insert_after(int value, int newvalue) {
        Node* newNode = new Node(newvalue);
        Node* temp = head;

        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value " << value << " not found.\n";
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void search(int x) {
        int pos = 1;
        Node* current = head;

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        while (current != NULL) {
            if (current->data == x) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Element not found\n";
    }

    void print() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void del_beg() {
        if (head == NULL) {
            cout << "Linked list is empty.\n";
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void del_end() {
        if (head == NULL) {
            cout << "Linked list is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head)
            head = NULL;
        else
            prev->next = NULL;

        delete temp;
    }

    void del_with_value(int value) {
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }
};

int main() {
    Linkedlist list;
    list.insert_beg(1);
    list.insert_beg(2);
    list.insert_beg(3);
    list.insert_beg(4);
    list.insert_end(5);
    list.insert_end(6);
    list.insert_at_pos(3, 7);
    list.insert_at_pos(10, 7);
    list.insert_after(5, 11);
    list.insert_after(25, 12);

    cout << "Elements of the list are: ";
    list.print();

    list.del_beg();
    list.print();

    list.del_end();
    list.print();

    list.del_with_value(5);
    list.print();

    cout << "Searching for 11: ";
    list.search(11);

    cout << "Searching for 100: ";
    list.search(100);

    return 0;
}
