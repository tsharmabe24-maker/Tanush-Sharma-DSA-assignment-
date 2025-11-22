#include <iostream>
using namespace std;

void diagonalMatrix(){
    int n;
    cout<<"Enter size of diagonal matrix: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element at ("<<i+1<<","<<i+1<<"): ";
        cin>>arr[i];
    }
    cout<<"Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<arr[i]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

void triDiagonalMatrix(){
    int n;
    cout<<"Enter size of tri-diagonal matrix: ";
    cin>>n;
    int size=3*n-2;
    int arr[size];
    cout<<"Enter elements:\n";
    for(int i=0;i<size;i++) cin>>arr[i];
    cout<<"Matrix:\n";
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(abs(i-j)<=1) cout<<arr[k++]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

void lowerTriangularMatrix(){
    int n;
    cout<<"Enter size of lower triangular matrix: ";
    cin>>n;
    int size=n*(n+1)/2;
    int arr[size];
    cout<<"Enter elements:\n";
    for(int i=0;i<size;i++) cin>>arr[i];
    cout<<"Matrix:\n";
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i) cout<<arr[k++]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

void upperTriangularMatrix(){
    int n;
    cout<<"Enter size of upper triangular matrix: ";
    cin>>n;
    int size=n*(n+1)/2;
    int arr[size];
    cout<<"Enter elements:\n";
    for(int i=0;i<size;i++) cin>>arr[i];
    cout<<"Matrix:\n";
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i) cout<<arr[k++]<<" ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}

void symmetricMatrix(){
    int n;
    cout<<"Enter size of symmetric matrix: ";
    cin>>n;
    int size=n*(n+1)/2;
    int arr[size];
    cout<<"Enter elements of upper triangle:\n";
    for(int i=0;i<size;i++) cin>>arr[i];
    cout<<"Matrix:\n";
    int k=0;
    int idx[n][n];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++) idx[i][j]=k++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j) cout<<arr[idx[i][j]]<<" ";
            else cout<<arr[idx[j][i]]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int choice;
    do{
        cout<<"\n1. Diagonal\n2. Tri-diagonal\n3. Lower triangular\n4. Upper triangular\n5. Symmetric\n0. Exit\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1: diagonalMatrix(); break;
            case 2: triDiagonalMatrix(); break;
            case 3: lowerTriangularMatrix(); break;
            case 4: upperTriangularMatrix(); break;
            case 5: symmetricMatrix(); break;
            case 0: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice\n"; break;
        }
    }while(choice!=0);
    return 0;
}
