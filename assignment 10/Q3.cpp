#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int num : nums) {
        mp[num]++;
    }
    
    cout << "Element frequencies:" << endl;
    for (auto pair : mp) {
        cout << pair.first << ": " << pair.second << endl;
   }
}

int main() {
    vector<int> nums = {2,3,2,4,3,2};
    frequencyCount(nums);
    return 0;
}