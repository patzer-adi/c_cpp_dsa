#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end()) {
                return true;  // duplicate found
            }
            s.insert(num);
        }
        return false;  // no duplicates
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test 1: " << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Test 2: " << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;

    // Test case 3
    vector<int> nums3 = {7, 8, 9, 10, 11};
    cout << "Test 3: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;

    return 0;
}
