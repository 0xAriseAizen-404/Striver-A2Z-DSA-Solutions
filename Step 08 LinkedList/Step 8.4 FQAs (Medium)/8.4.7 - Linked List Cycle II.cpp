/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// BruteForce Solution
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         set<ListNode*> seen;
//         ListNode* temp = head;
//         while (temp) {
//             if (!seen.insert(temp).second) return temp;
//             temp = temp->next;
//         }
//         return NULL;
//     }
// };
// Storing in a Set and Iterating Over it
// O(n)
// O(n)

// Optimal Solution
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// Floyd's Detection Cycle
// O(n)
// O(1)