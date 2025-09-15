#include <iostream>
#include <string>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top == MAX - 1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stack[++top] = c;
    }
}

char pop(){
    if(top == -1){
        cout<<"Stack Underflow"<<endl;
        return '\0';
    }
    else{
        return stack[top--];
    }
}

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    for(char c : str){
        push(c);
    }
    cout<<"Reversed string: ";
    while(top != -1){
        cout<<pop();
    }
    cout<<endl;
    return 0;
}