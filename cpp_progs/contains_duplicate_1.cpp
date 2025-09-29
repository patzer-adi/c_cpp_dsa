#include <iostream>
#include <vector>
#include <algorithm>  // for sort
using namespace std;

//O(n log n) complexity...... first it sorts and then finds out duplicates... fun algo


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort first
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;  // duplicate found
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
    vector<int> nums3 = {10, 20, 30, 40, 50, 10};
    cout << "Test 3: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;

    return 0;
}
