#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    for (int num : nums) {
        if (freq[num] == 1) {
            return num;
        }
    }
    
    return -1; 
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    int result = firstNonRepeating(nums);
    
    if (result != -1) {
        cout << "First non-repeating element: " << result << endl;
    } else {
        cout << "All elements are repeating" << endl;
    }
    
    return 0;
}