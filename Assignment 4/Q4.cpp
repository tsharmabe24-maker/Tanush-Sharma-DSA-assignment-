#include <iostream>
#include <queue>
#include <string>
using namespace std;

void notrepeating(string str){
    queue<char> q;
    int freq[26] = {0};
    for(char c: str){
        if(c == ' '){
            continue;
        }
        freq[c - 'a']++;
        q.push(c);
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1 ";
        } else {
            cout<<q.front()<<" ";
        }
    }
    cout << endl;
}

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);

    notrepeating(str);
    return 0;
}