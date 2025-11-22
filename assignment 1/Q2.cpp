#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int k = 0;

void unique(int brr[], int n){
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<k;j++){
            if(brr[i]==arr[j]){
                flag = true;
                break;
            }
        }
        if(!flag && k<MAX){
            arr[k] = brr[i];
            k++;
        }
    }
}

int main(){
    int brr[] = {1,2,3,2,4,1,5};
    int n = sizeof(brr)/sizeof(brr[0]);
    unique(brr,n);
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}