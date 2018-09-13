#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/add-two-numbers/description/
// g++ addTwoNumbers.cpp --std=c++11 -W && ./a.out
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = NULL, *now = NULL;
        while(l1 != NULL || l2 != NULL) {
            int i1 = 0, i2 = 0;
            if(l1 != NULL) {
                i1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                i2 = l2->val;
                l2 = l2->next;
            }

            int i = i1 + i2 + carry; 
            carry = i / 10;
            int value = i % 10;
            if(now != NULL) {
                now->next = new ListNode(value);
                now = now->next;
            }
            else {  // first time
                ans = new ListNode(value);
                now = ans;
            }
        }

        if(carry != 0) {
            now->next = new ListNode(carry);
        }

        return ans;
    }
};

int main()
{
    auto so = Solution();
    ListNode ln1 = ListNode(2);
    ListNode ln2 = ListNode(4);
    ListNode ln3 = ListNode(3);
    ln1.next = &ln2;
    ln2.next = &ln3;

    ListNode ln4 = ListNode(5);
    ListNode ln5 = ListNode(6);
    ListNode ln6 = ListNode(8);
    ln4.next = &ln5;
    ln5.next = &ln6;

    ListNode *ans = so.addTwoNumbers(&ln1, &ln4);
    while (ans != NULL) {
        cout << ans->val;
        ans = ans->next;
    }
    cout << endl;

    return 0;
}



