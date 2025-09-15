#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void menu(){
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Is Empty"<<endl;
    cout<<"4. Is Full"<<endl;
    cout<<"5. Display"<<endl;
    cout<<"6. Peek"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Enter your choice: ";
}

int isFull(){
    return top == MAX - 1;
}

int isEmpty(){
    return top == -1;
}

void push(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stack[++top] = x;
        cout<<x<<" pushed to stack"<<endl;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<stack[top--]<<" popped from stack"<<endl;
    }
}

void peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Top element is "<<stack[top]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack elements are: ";
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int choice, value;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(isEmpty()){
                    cout<<"Stack is empty"<<endl;
                }
                else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;
            case 4:
                if(isFull()){
                    cout<<"Stack is full"<<endl;
                }
                else{
                    cout<<"Stack is not full"<<endl;
                }
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice != 7);
    return 0;
}