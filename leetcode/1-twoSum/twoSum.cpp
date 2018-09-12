#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto ans = vector<int>();
        auto num2Index = map<int, int>();
        for (unsigned i = 0; i < nums.size(); i++) {
            int min = target - nums[i];
            auto it1 = num2Index.find(nums[i]); // 利用map的便利性
            auto it2 = num2Index.find(min);
            if(it2 != num2Index.end()) {        // find complement in map
                ans.push_back(it2->second);
                ans.push_back(i);
                return ans;
            }
            else if(it1 != num2Index.end()) {  // keep first ind when repeat
                continue;   
            }
            else {
                num2Index[nums[i]] = i; // add ind
            }
        }

        return ans;
    }

    vector<int> twoSumLow(vector<int>& nums, int target) {
        auto ans = vector<int>();
        auto num2Index = map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            auto it = num2Index.find(nums[i]);
            if(it != num2Index.end()) {     // 数字重复 
                if(nums[i] * 2 == target) {
                    ans.push_back(it->second);
                    ans.push_back(i);
                    return ans;
                }
                continue;       // 保留第一个出现的位置
            }
            num2Index[nums[i]] = i;
        }
        sort(nums.begin(), nums.end()); // sort本身复杂度较高
        bool found = false;
        for(int i=0, j=nums.size()-1; i < j; i++) { // 利用数组的有序性
            for(/* NULL */; i < j; j--) {
                if(nums[j] > min) {
                    continue;
                } 
                else if(nums[j] < min) {
                    break;
                }
                else {  // nums[j] == min, equal
                    // cout << nums[i] << ", " << nums[j] << endl;
                    found = true;
                    break;
                }
            }

            if (found) {
                ans.push_back(num2Index[nums[i]]);
                ans.push_back(num2Index[nums[j]]);
                break;
            }
        }

        return ans;
    }
};

int main()
{
    auto so = Solution();
    auto nums = vector<int>{5, 5, 2, 2, 7, 11, 15};
    auto numsCpy = nums;
    auto target = 10;

    vector<int> ans = so.twoSum(numsCpy, target);
    for (auto &i : ans) {
        cout << nums[i] << endl;
    }
    cout << "target=" << target << endl;

    return 0;
}


