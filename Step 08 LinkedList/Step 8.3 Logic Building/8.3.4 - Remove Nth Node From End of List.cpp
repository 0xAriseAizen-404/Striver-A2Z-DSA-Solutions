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

// BruteForce Solution
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* temp = head;
//         int count = 0;
//         while (temp) {
//             count += 1;
//             temp = temp->next;
//         }
//         temp = head;
//         count = count - n - 1;
//         if (count == -1) return head->next;
//         while (count-- > 0) temp = temp->next;
//         temp->next = temp->next->next;
//         return head;
//     }
// };
// Count length → compute (L - n)th → bypass
// TC: O(n)
// SC: O(1)

// Optimal Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        // Finding exact opposite position of n-1 Node
        for (int i=0; i<n; ++i) fast = fast->next;
        if (fast == NULL) return head->next;

        // slow and fast act as a window and moving one at a time to the exact n-1 Node;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
// Two-pointer window (advance fast by n) → delete slow->next
// TC: O(n)
// SC: O(1)