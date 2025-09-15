#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate(string str){
    stack<int> s;
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        if(c == ' ') continue;
        if(c >= '0' && c <= '9'){
            s.push(c - '0');
        }
        else{
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch(c){
                case '+': 
                    s.push(val1 + val2); 
                    break;
                case '-': 
                    s.push(val1 - val2); 
                    break;
                case '*': 
                    s.push(val1 * val2); 
                    break;
                case '/': 
                    s.push(val1 / val2); 
                    break;
                case '^':{
                    int res = 1;
                    for(int j = 0; j < val2; j++) res *= val1;
                    s.push(res);
                    break;
                }
            }
        }
    }
    return s.top();
}

int main(){
    string str;
    cout<<"Enter a postfix expression: ";
    cin>>str;
    cout<<"Evaluated Result: "<< evaluate(str)<<endl;
    return 0;
}