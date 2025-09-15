#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
    int arr[SIZE];
    int front, rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return (front==-1 && rear==-1);
    }

    bool isFull(){
        return (rear == SIZE-1);
    }

    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow."<<endl;
            return;
        }
        if(isEmpty()){
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout<<value<<" enqueued to queue."<<endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow."<<endl;
            return;
        }
        cout<<arr[front]<<" dequeued from queue."<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"Front element is: "<<arr[front]<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for(int i=front; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int maain(){
    Queue q;
    int choice, value;
    do{
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if(q.isEmpty()){
                    cout<<"Queue is empty."<<endl;
                } else {
                    cout<<"Queue is not empty."<<endl;
                }
                break;
            case 6:
                if(q.isFull()){
                    cout<<"Queue is full."<<endl;
                } else {
                    cout<<"Queue is not full."<<endl;
                }
                break;
            case 0:
                cout<<"Exiting..."<<endl;
                break; 
        }
    }while(choice!=0);
    return 0;
}