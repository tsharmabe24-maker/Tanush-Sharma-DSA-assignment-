#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op){
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    else return 0;
}

bool Operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string intopost(string infix){
    stack<char> s;     
    string postfix = "";

    for (char c : infix){
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '('){
            s.push(c);
        }
        else if (c == ')'){
            while (!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')  s.pop();
        }
        else if (Operator(c)){
            while (!s.empty() && precedence(s.top()) >= precedence(c) && c != '^'){
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout<<"Enter Infix expression: ";
    cin>>infix;

    string postfix = intopost(infix);
    cout<<"Postfix expression: "<<postfix<<endl;

    return 0;
}
