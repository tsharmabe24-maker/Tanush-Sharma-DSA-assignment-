#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>&A, vector<int>&B){
    unordered_set<int> s(A.begin(), A.end());
    vector<int> result;
    for(int num : B){
        if(s.count(num)){
            result.push_back(num);
            s.erase(num);
        }
    }
    return result;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    vector<int> common = commonElements(A, B);
    
    cout << "Common elements: ";
    for(int num : common){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}