#include <vector>
#include<iostream>
#include<map>
using namespace std;
// O(n log n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> d;
        for(int i = 0; i < nums.size(); i++)
        {
        int tar = target - nums[i];
            if(d.find(tar) != d.end() )
            {
            ans.push_back(d[tar]);
            ans.push_back(i);
            break;
            }
            d[nums[i]] = i;
        }
        return ans;
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
