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
//     ListNode* sortList(ListNode* head) {
//         vector<int> v;
//         ListNode* temp = head;
//         while (temp) {
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
//         sort(v.begin(), v.end());
//         temp = head;
//         int i = 0;
//         while (temp) {
//             temp->val = v[i++];
//             temp = temp->next;
//         }
//         return head;
//     }
// };
// Copy values → sort → write back
// TC: O(n log n)
// SC: O(n)


// Optimal Solution
class Solution {
private:
    ListNode* getMidNode(ListNode* fast) {
        ListNode* slow = nullptr;
        while (fast && fast->next) {
            slow = (slow == nullptr) ? fast : slow->next;
            fast = fast->next->next;
        }
        ListNode* midNode = slow->next;
        slow->next = nullptr;
        return midNode;
    }
    ListNode* merge(ListNode* leftPart, ListNode* rightPart) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (leftPart && rightPart) {
            if (leftPart->val < rightPart->val) {
                curr->next = leftPart;
                leftPart = leftPart->next;
            } else {
                curr->next = rightPart;
                rightPart = rightPart->next;
            }
            curr = curr->next;
        }
        curr->next = leftPart ? leftPart : rightPart;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* midNode = getMidNode(head);
        ListNode* leftPart = sortList(head);
        ListNode* rightPart = sortList(midNode);
        return merge(leftPart, rightPart);
    }
};
// Bottom-up merges on runs of size 1,2,4,...
// TC: O(n log n)
// SC: O(1)