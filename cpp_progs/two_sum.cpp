#include <vector>
#include<iostream>
// O(n^2)
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); ++i) 
        {
            for(int j = i + 1; j < (int)nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
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
