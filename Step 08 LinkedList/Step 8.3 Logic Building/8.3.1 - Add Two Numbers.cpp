/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tailA = l1;
        ListNode* tailB = l2;
        int carry = 0;
        int value = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (tailA || tailB) {
            value = 0;
            if (tailA) {
                value += tailA->val;
                tailA = tailA->next;
            }
            if (tailB) {
                value += tailB->val;
                tailB = tailB->next;
            }
            value += carry;
            
            dummy->next = new ListNode(value % 10);
            dummy = dummy->next;
            carry = value / 10;
        }
        if (carry) dummy->next = new ListNode(carry);
        return curr->next;
    }
};
// Digit-wise addition with carry using a dummy head (single pass over both lists)
// TC: O(max(n, m))
// SC: O(max(n, m))   // for the output list; auxiliary extra space is O(1)