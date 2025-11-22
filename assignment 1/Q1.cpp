#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int size = 0;

void showMenu() {
    cout << "Menu:\n";
    cout << "1. CREATE\n";
    cout << "2. DISPLAY\n";
    cout << "3. INSERT\n";
    cout << "4. DELETE\n";
    cout << "5. LINEAR SEARCH\n";
    cout << "6. EXIT\n";
}

void create(){
    cout << "Enter number of elements: ";
    cin >> size;
    if(size > MAX) {
        cout<<"Maximum Limit Exceeded";
        size = 0;
        return;
    }
    cout << "Enter elements:\n";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

void display() {
    if(size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos,element;
    if(size==MAX){
        cout<<"Array is full, cannot insert more elements.\n";
        return;
    }
    cout << "Enter position to insert (0 to " << size << "): ";
    cin >> pos;
    if(pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter element to insert: ";
    cin >> element; 
    for(int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

void del(){
    int pos;
    if(size == 0) {
        cout << "Array is empty, cannot delete elements.\n";
        return;
    }
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> pos;
    if(pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return;
    }
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully.\n";
}

void linearsearch() {
    if(size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
    cout << "Element not found in the array.\n";
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                linearsearch();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);
    return 0;
}