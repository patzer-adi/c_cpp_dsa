#include <vector>
#include<iostream>
#include<map>
using namespace std;
// O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int tar = target - nums[i];
            if(mp.count(tar))
            {
                return {mp[tar], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto res = s.twoSum(nums, target);
    for (int i : res) cout << i << " ";
    return 0;
}
