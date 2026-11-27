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
//     bool isPalindrome(ListNode* head) {
//         string str = "";
//         ListNode* temp = head;
//         while (temp) {
//             str += to_string(temp->val);
//             temp = temp->next;
//         }
//         string str2 = str;
//         reverse(str.begin(), str.end());
//         return str == str2;
//     }
// };
// Copy values → reverse array → write back/compare
// TC: O(n)
// SC: O(n)

// Better Solution
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (!head || !head->next) return true;
//         stack<int> st;
//         ListNode *slow=head, *fast=head;
//         while (fast && fast->next) { 
//             st.push(slow->val); 
//             slow=slow->next; 
//             fast=fast->next->next;
//         }
//         if (fast) slow = slow->next; // skip middle for odd
//         while (slow) { 
//             if (st.top()!=slow->val) return false; 
//             st.pop(); slow=slow->next; 
//         }
//         return true;
//     }
// };

// Optimal Solution
class Solution {
private:
    ListNode* findMedianNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode *head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_node = NULL;
        while (curr) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* midNode = findMedianNode(head);
        midNode = reverseList(midNode);
        ListNode* temp = head;
        ListNode* mid_temp = midNode;
        bool answer = true;
        while (mid_temp) {
            if (temp->val != mid_temp->val) {
                answer = false;
                break;
            }
            temp = temp->next;
            mid_temp = mid_temp->next;
        }
        reverseList(midNode);
        return answer;
    }
};
// Reverse first half during mid-finding → compare → reverse back
// TC: O(n)
// SC: O(1)