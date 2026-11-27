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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         set<ListNode*> seen;
//         ListNode* temp = headA;
//         while (temp) {
//             seen.insert(temp);
//             temp = temp->next;
//         }
//         temp = headB;
//         while (temp) {
//             if (!seen.insert(temp).second) return temp;
//             temp = temp->next;
//         }
//         return NULL;
//     }
// };
// Store all nodes of A in a hash set → first node of B found in set is intersection
// TC: O(n + m)
// SC: O(n)


// Optimal Solution 01
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         ListNode* tailA = headA;
//         while (tailA->next) tailA = tailA->next;
//         tailA->next = headA; // creating a Loop;

//         ListNode* slow = headB;
//         ListNode* fast = headB;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) { // there is a loop
//                 slow = headB;
//                 while (slow != fast) {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }
//                 tailA->next = NULL;
//                 return slow;
//             }
//         }
//         tailA->next = NULL;
//         return NULL;
//     }
// };
// Link tailA->next = headA to form cycle → run Floyd on B → restore
// TC: O(n + m)
// SC: O(1)

// Optimal Solution 02
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return NULL;
        ListNode* tailA = headA;
        ListNode* tailB = headB;
        while (tailA || tailB) {
            if (tailA == NULL) tailA = headB;
            if (tailB == NULL) tailB = headA;

            if (tailA == tailB) return tailA;
            else {
                tailA = tailA->next;
                tailB = tailB->next;
            }
        }
        return NULL;
    }
};
// Traverse A then B, and B then A; pointers meet at intersection or NULL
// TC: O(n + m)
// SC: O(1)