#include <iostream>
#include <vector>
using namespace std;
// n
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] > target) {
                return i;
            } else if (i == nums.size() - 1) {
                return i + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;

    // Example 1
    vector<int> nums1 = {1,3,5,6};
    int target1 = 5;
    cout << "Input: [1,3,5,6], target = 5 → Output: " 
         << s.searchInsert(nums1, target1) << endl;

    // Example 2
    vector<int> nums2 = {1,3,5,6};
    int target2 = 2;
    cout << "Input: [1,3,5,6], target = 2 → Output: " 
         << s.searchInsert(nums2, target2) << endl;

    // Example 3
    vector<int> nums3 = {1,3,5,6};
    int target3 = 7;
    cout << "Input: [1,3,5,6], target = 7 → Output: " 
         << s.searchInsert(nums3, target3) << endl;

    // Example 4
    vector<int> nums4 = {1,3,5,6};
    int target4 = 0;
    cout << "Input: [1,3,5,6], target = 0 → Output: " 
         << s.searchInsert(nums4, target4) << endl;

    return 0;
}
