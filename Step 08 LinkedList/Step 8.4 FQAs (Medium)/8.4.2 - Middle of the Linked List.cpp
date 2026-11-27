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

// BruteForce
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int count = 0;
//         ListNode* temp = head;
//         while (temp) {
//             count++;
//             temp = temp->next;
//         }
//         int mid = (count + 1) / 2;
//         bool even_odd = count & 1;
//         temp = head;
//         count = 1;
//         while (count++ < mid) temp = temp->next;
//         return even_odd ? temp : temp->next;
//     }
// };
// TC: O(n + n) = O(n)
// SC: O(1)

// Optimal
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// TC: O(n)
// SC: O(1)