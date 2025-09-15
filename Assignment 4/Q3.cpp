#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &q){
    int n = q.size();
    if(n%2!=0){
        cout<<"Queue has odd number of elements, cannot interleave."<<endl;
        return;
    }
    int h = n/2;
    queue<int> first;
    for(int i=0;i<h;i++){
        first.push(q.front());
        q.pop();
    }
    while(!first.empty()){
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
}
void display(queue<int> q){
    if(q.empty()){
        cout<<"Queue is empty."<<endl;
        return;
    }
    cout<<"Queue elements are: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    int n, val;
    cout<<"Enter number of elements (even): ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>val;
        q.push(val);
    }
    cout<<"Original "<<endl;
    display(q);

    interleave(q);

    cout<<"Interleaved "<<endl;
    display(q);
    return 0;
}