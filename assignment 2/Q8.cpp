#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0; 

    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) { 
            if (arr[i] == arr[j]) { 
                flag = false;
                break;
            }
        }
        if (flag) {
            count++;
        }
    }

    cout << "Total distinct elements: " << count << endl;

    return 0;
}
