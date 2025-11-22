#include <iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"Enter number of rows and columns: ";
    cin>>r>>c;
    int arr[r][c];
    int brr[c][r];
    cout<<"Enter elements of the matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            brr[i][j] = arr[j][i];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
}