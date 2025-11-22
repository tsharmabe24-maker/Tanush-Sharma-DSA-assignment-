#include <iostream>
using namespace std;

void concat(char a[],char b[]){
    int i=0,j=0;
    while(a[i]!='\0') i++;
    while(b[j]!='\0'){
        a[i]=b[j];
        i++; j++;
    }
    a[i]='\0';
}

void reverse(char s[]){
    int len=0;
    while(s[len]!='\0') len++;
    for(int i=0;i<len/2;i++){
        char t=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=t;
    }
}

void removeVowels(char s[]){
    int i=0,j=0;
    while(s[i]!='\0'){
        char c=s[i];
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
             c=='A'||c=='E'||c=='I'||c=='O'||c=='U')){
            s[j++]=c;
        }
        i++;
    }
    s[j]='\0';
}

void sortStrings(char arr[][50],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int k=0;
            while(arr[i][k]==arr[j][k] && arr[i][k]!='\0') k++;
            if(arr[i][k]>arr[j][k]){
                char temp[50];
                int m=0;
                while(arr[i][m]!='\0'){ temp[m]=arr[i][m]; m++; }
                temp[m]='\0';
                m=0;
                while(arr[j][m]!='\0'){ arr[i][m]=arr[j][m]; m++; }
                arr[i][m]='\0';
                m=0;
                while(temp[m]!='\0'){ arr[j][m]=temp[m]; m++; }
                arr[j][m]='\0';
            }
        }
    }
}

void toLower(char &c){
    if(c>='A'&&c<='Z') c=c+32;
}

int main(){
    char str1[100],str2[50];
    cout<<"Enter first string: ";
    cin.getline(str1,100);
    cout<<"Enter second string: ";
    cin.getline(str2,50);

    concat(str1,str2);
    cout<<"Concatenated: "<<str1<<endl;

    reverse(str1);
    cout<<"Reversed: "<<str1<<endl;

    removeVowels(str1);
    cout<<"Without vowels: "<<str1<<endl;

    int n;
    cout<<"Enter number of strings: ";
    cin>>n;
    cin.ignore();
    char arr[10][50];
    for(int i=0;i<n;i++){
        cout<<"Enter string "<<i+1<<": ";
        cin.getline(arr[i],50);
    }
    sortStrings(arr,n);
    cout<<"Sorted strings:\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;

    char ch;
    cout<<"Enter char to convert to lowercase: ";
    cin>>ch;
    toLower(ch);
    cout<<"Lowercase: "<<ch<<endl;
    return 0;
}
