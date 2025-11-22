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
    int a,b;
    cout<<"Enter row and coiumn of other matrix: ";
    cin>>a>>b;
    int brr[a][b];
    int crr[r][b];
    if(c!=a){
        cout<<"Matrix multiplication not possible";
    }
    else{
        cout<<"Enter elements of second matrix:\n";
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin>>brr[i][j];
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<b;j++){
            crr[i][j] = 0;
            for(int k=0;k<c;k++){
                crr[i][j] += arr[i][k]*brr[k][j];
            }
        }
    }
    cout<<"Resultant matrix after multiplication:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<b;j++){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}