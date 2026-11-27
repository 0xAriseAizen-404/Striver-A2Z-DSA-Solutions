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
//     ListNode* reverseList(ListNode* head) {
//         if (head == NULL || head->next == NULL) return head;
//         vector<int> vi;
//         ListNode* temp = head;
//         while (temp) {
//             vi.push_back(temp->val);
//             temp = temp->next;
//         }
//         reverse(vi.begin(), vi.end());
//         temp = head;
//         int i = 0;
//         while (temp) {
//             temp->val = vi[i++];
//             temp = temp->next;
//         }
//         return head;
//     }
// };
// Copy values → reverse array → write back
// TC: O(n)
// SC: O(n)

// Optimal Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next_node = NULL;
        ListNode* curr = head;
        while (curr) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
};
// In-place pointer reversal
// TC: O(n)
// SC: O(1)