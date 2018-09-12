#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto num2Index = map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            num2Index[nums[i]] = i;
        }
        auto ans = vector<int>();
        sort(nums.begin(), nums.end());
        bool found = false;
        for(int i=0, j=nums.size()-1; i < j; i++) {
            int min = target - nums[i];
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
    auto nums = vector<int>{5, 6, 2, 2, 7, 11, 15};
    auto numsCpy = nums;
    auto target = 4;

    vector<int> ans = so.twoSum(numsCpy, target);
    for (auto &i : ans) {
        cout << nums[i] << endl;
    }
    cout << "target=" << target << endl;

    return 0;
}


