#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/two-sum/description/
// g++ addTwoNumbers.cpp --std=c++11 -W && ./a.out
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto ans = vector<int>();


        ans.push_back(5);
        ans.push_back(6);
        return ans;
    }
};

int main()
{
    auto so = Solution();
    auto nums = vector<int>{2, 7, 11, 15};
    auto target = 9;

    vector<int> ans = so.twoSum(nums, target);
    for (auto &i : ans) {
        cout << i << endl;
    }

    return 0;
}



