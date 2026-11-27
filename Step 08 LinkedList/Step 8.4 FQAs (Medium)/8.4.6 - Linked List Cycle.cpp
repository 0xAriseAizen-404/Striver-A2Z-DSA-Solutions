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
//     bool hasCycle(ListNode *head) {
//         if (!head || !head->next) return false;
//         set<ListNode*> seen;
//         ListNode* temp = head;
//         while (temp) {
//             if (!seen.insert(temp).second) return true;
//             temp = temp->next;
//         }
//         return false;
//     }
// };
// TC: O(n)
// SC: O(n)

// Optimal Solution
class Solution {
public: 
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// Floyd's Cycle Detection
// TC: O(n)
// SC: O(1)