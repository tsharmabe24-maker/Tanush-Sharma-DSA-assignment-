#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q;
    public:
    void push(int val){
        int size = q.size();
        q.push(val);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
        cout<<val<<" pushed to stack."<<endl;
    }

    void pop(){
        if(q.empty()){
            cout<<"Stack Underflow."<<endl;
            return;
        }
        cout<<q.front()<<" popped from stack."<<endl;
        q.pop();
    }

    int top(){
        if(q.empty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
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