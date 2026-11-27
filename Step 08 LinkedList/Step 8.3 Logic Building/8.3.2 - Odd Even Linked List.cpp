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
//     ListNode* oddEvenList(ListNode* head) {
//         if (!head || !head->next) return head;
//         vector<int> odd, even;
//         int idx = 1;
//         for (ListNode* cur = head; cur; cur = cur->next, ++idx)
//             (idx & 1 ? odd : even).push_back(cur->val);

//         ListNode* cur = head;
//         for (int x : odd)  { cur->val = x; cur = cur->next; }
//         for (int x : even) { cur->val = x; cur = cur->next; }
//         return head;
//     }
// };
// Copy values by position → write back (stable nodes, mutate values only)
// TC: O(n)
// SC: O(n)

// Optimal Solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* odd_temp = odd;
        ListNode* even_temp = even;
        while (even_temp && even_temp->next) {
            odd_temp->next = even_temp->next;
            odd_temp = odd_temp->next;
            even_temp->next = odd_temp->next;
            even_temp = even_temp->next;
        }
        odd_temp->next = even;
        return odd;
    }
};
// In-place odd/even rewiring with two runners
// TC: O(n)
// SC: O(1)