#include <iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"Enter number of rows and columns: ";
    cin>>r>>c;
    int arr[r][c];
    cout<<"Enter elements of the matrix:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Sum of each row:\n";
    for(int i=0;i<r;i++){
        int sum = 0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        cout<<"Row "<<i<<": "<<sum<<endl;
    }
    cout<<"Sum of each column:\n";
    for(int j=0;j<c;j++){
        int sum = 0;
        for(int i=0;i<r;i++){
            sum += arr[i][j];
        }
        cout<<"Column "<<j<<": "<<sum<<endl;
    }
    return 0;
}