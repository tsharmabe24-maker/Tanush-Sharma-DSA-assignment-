#include <iostream>
using namespace std;

#define SIZE 5

class circQueue{
    int arr[SIZE];
    int front, rear;
    public:
    circQueue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }
    bool isFull(){
        return ((rear + 1) % SIZE == front);
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue Overflow."<<endl;
            return;
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % SIZE;
        }
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
        }
        else{
            front = (front + 1) % SIZE;
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
        cout<<"Queue elements are: ";
        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear){
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout<<endl;
    }
};

int main(){
    circQueue q;
    int choice, value;
    do{
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
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
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    } while(choice != 5);
    return 0;
}