#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
// g++ longestSubStr.cpp --std=c++11 -W && ./a.out
class Solution {
public:
    int lengthOfLongestSubstring2(string s) {
        int alphaPos[256] = {0}; 
        vector<int> cntArr(s.length() + 1);
        int max = 0;

        // s's index begins from 1
        for(unsigned i=1; i <= s.length(); i++) {
            char c = s[i-1];
            if(alphaPos[c] != 0) {  // repeated
                int prvPos = alphaPos[c];
                // cout << c << ", " << prvPos << endl;
                // clear alphaPos
                for(int j=0; j<prvPos; j++) {
                    char cs = s[prvPos-j-1];
                    // cout << cs << endl;
                    alphaPos[cs] = 0;
                    if(cntArr[prvPos-j] == 1) {
                        break;
                    }
                }

                // clear cntArr
                for(int j=i-1; j>=prvPos; j--) { 
                    // j can't increse, because it will lost the value of countArr[prvPos]
                    // j=prvPos, incase of neighbor is repeated
                    cntArr[j] = cntArr[j] - cntArr[prvPos];     
                    // cout << "update:" << s[j-1] << ", " << cntArr[j] << endl;
                }
            }
            // update towArr
            alphaPos[c] = i;
            cntArr[i] = cntArr[i-1] + 1; // firt time, cntArr[1] = 0 + 1;

            if(max < cntArr[i]) {
                max = cntArr[i];
            }
            // cout << i << "," << max << endl;
        }

        return max;
    }

    int lengthOfLongestSubstring(string s) {
        int alphaPos[256] = {0}; 
        vector<int> cntArr(s.length() + 1);
        int max = 0;

        // s's index begins from 1
        unsigned newBegin = 1;
        for(unsigned i=1; i <= s.length(); i++) {
            char c = s[i-1];
            // 简单方法检测字符的位置当前是否有效，可以避免全部更新为0
            if(alphaPos[c] >= newBegin) {  // repeated
                int prvPos = alphaPos[c];
                newBegin = prvPos + 1;
                cout << newBegin << "," << c << endl;
                // clear cntArr
                for(int j=i-1; j>=prvPos; j--) { 
                    // j can't increse, because it will lost the value of countArr[prvPos]
                    // j=prvPos, incase of neighbor is repeated
                    cntArr[j] = cntArr[j] - cntArr[prvPos];     
                    // cout << "update:" << s[j-1] << ", " << cntArr[j] << endl;
                }
            }
            // update towArr
            alphaPos[c] = i;
            cntArr[i] = cntArr[i-1] + 1; // firt time, cntArr[1] = 0 + 1;

            if(max < cntArr[i]) {
                max = cntArr[i];
            }
            // cout << i << "," << max << endl;
        }

        return max;
    }
};

int main()
{
    auto so = Solution();

    string s = "tmmzuxt";
    int len = so.lengthOfLongestSubstring(s);
    cout << len << endl;
    len = so.lengthOfLongestSubstring2(s);
    cout << len << endl;

    return 0;
}



