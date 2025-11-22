#include<iostream>
using namespace std;

struct Sparse {
    int row, col, val;
};

void readSparse(Sparse s[]) {
    cout<<"Enter number of rows, cols, and non-zero values: ";
    cin>>s[0].row>>s[0].col>>s[0].val;
    cout<<"Enter row, col, and value for each non-zero element:\n";
    for(int i=1;i<=s[0].val;i++) cin>>s[i].row>>s[i].col>>s[i].val;
}

void display(Sparse s[]) {
    cout<<"Row Col Val\n";
    for(int i=0;i<=s[0].val;i++)
        cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val<<"\n";
}

void transpose(Sparse a[], Sparse b[]) {
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    if(a[0].val>0){
        int k=1;
        for(int col=0;col<a[0].col;col++){
            for(int i=1;i<=a[0].val;i++){
                if(a[i].col==col){
                    b[k].row=a[i].col;
                    b[k].col=a[i].row;
                    b[k].val=a[i].val;
                    k++;
                }
            }
        }
    }
}

void add(Sparse a[], Sparse b[], Sparse c[]) {
    if(a[0].row!=b[0].row || a[0].col!=b[0].col) {
        cout<<"Addition not possible\n"; return;
    }
    int i=1,j=1,k=1;
    c[0].row=a[0].row; c[0].col=a[0].col;
    while(i<=a[0].val && j<=b[0].val){
        if(a[i].row==b[j].row && a[i].col==b[j].col){
            c[k].row=a[i].row; c[k].col=a[i].col; c[k].val=a[i].val+b[j].val;
            i++; j++; k++;
        }
        else if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)){
            c[k++]=a[i++];
        } else {
            c[k++]=b[j++];
        }
    }
    while(i<=a[0].val) c[k++]=a[i++];
    while(j<=b[0].val) c[k++]=b[j++];
    c[0].val=k-1;
}

void multiply(Sparse a[], Sparse b[], Sparse c[]) {
    if(a[0].col!=b[0].row){
        cout<<"Multiplication not possible\n"; return;
    }
    Sparse bT[100];
    transpose(b,bT);
    c[0].row=a[0].row;
    c[0].col=b[0].col;
    int k=1;
    for(int i=1;i<=a[0].row;i++){
        for(int j=1;j<=bT[0].row;j++){
            int sum=0;
            for(int x=1;x<=a[0].val;x++){
                if(a[x].row==i-1){
                    for(int y=1;y<=bT[0].val;y++){
                        if(bT[y].row==j-1 && bT[y].col==a[x].col){
                            sum+=a[x].val*bT[y].val;
                        }
                    }
                }
            }
            if(sum!=0){
                c[k].row=i-1; c[k].col=j-1; c[k].val=sum; k++;
            }
        }
    }
    c[0].val=k-1;
}

int main(){
    Sparse A[100],B[100],C[100],T[100],M[100];
    cout<<"Enter first matrix:\n";
    readSparse(A);
    cout<<"First Matrix:\n"; display(A);

    cout<<"Enter second matrix:\n";
    readSparse(B);
    cout<<"Second Matrix:\n"; display(B);

    transpose(A,T);
    cout<<"Transpose of First Matrix:\n"; display(T);

    add(A,B,C);
    cout<<"Addition Result:\n"; display(C);

    multiply(A,B,M);
    cout<<"Multiplication Result:\n"; display(M);
}
