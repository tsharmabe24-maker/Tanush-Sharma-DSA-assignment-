#include <bits/stdc++.h>
using namespace std;

void impSelectionSort(vector<int> & arr){
    int start = 0;
    int end = arr.size() - 1;
    while(start<end){
        int mini = start;
        int maxi = start;
        for(int i=start;i<=end;i++){
            if(arr[i]<arr[mini]){
                mini = i;
            }
            if(arr[i]>arr[maxi]){
                maxi = i;
            }
        }
        swap(arr[mini], arr[start]);
        if(maxi==start){
            maxi = mini;
        }
        swap(arr[end], arr[maxi]);
        start++;
        end--;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    impSelectionSort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}