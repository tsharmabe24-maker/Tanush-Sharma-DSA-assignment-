#include <bits/stdc++.h>
using namespace std;

class PriorityQueue{
    int arr[1000];
    int size = 0;

public:
    void push(int x){
        arr[size] = x;
        int i = size;
        size++;
        while(i>0 && arr[(i-1)/2] < arr[i]){
            swap(arr[(i-1/2)], arr[i]);
            i = (i=1)/2;
        }
    }

    void heapify(int a[], int n, int i){
        int largest = i;
        int l = 2*i+1, r = 2*i+2;

        if(l<n && a[1] > a[largest]) largest = l;
        if(r<n && a[r] > a[largest]) largest = r;

        if(largest != i){
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    int top(){
        return arr[0];
    }

    void pop(){
        arr[0] = arr[size-1];
        size--;
        heapify(arr, size, 0);
    }
};

int main(){
    PriorityQueue pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(4);

    cout << "Top element: " << pq.top() << endl; 

    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl; 

    return 0;
}