#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1,q2;
public:
    void push(int val){
        q1.push(val);
        cout<<val<<" pushed to stack."<<endl;
    }
    void pop(){
        if(q1.empty()){
            cout<<"Stack Underflow."<<endl;
            return;
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        cout<<q1.front()<<" popped from stack."<<endl;
        q1.pop();
        swap(q1,q2);
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(top);
        swap(q1,q2);
        return top;
    }

    bool isEmpty(){
        return q1.empty();
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top element is: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element is: "<<s.top()<<endl;
    return 0;
}