#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool matching(char a, char b){
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

bool balanced(const string &some){
    stack<char> s;

    for (char ch : some){
        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']'){
            if (s.empty()) return false;          
            char topChar = s.top();               
            s.pop();                             
            if (!matching(topChar, ch)) return false;
        }
    }
    return s.empty(); 
}

int main(){
    string some;
    cout<<"Enter an expression: ";
    getline(cin, some);

    if(balanced(some)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}