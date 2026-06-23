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

// Optimal Solution
class Solution {
private:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) const {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> minHeap;
        for (auto node: lists) if(node) minHeap.push(node);
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!minHeap.empty()) {
            ListNode *node = minHeap.top(); minHeap.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) minHeap.push(node->next);
        }
        return dummy.next;
    }
};
// TC: O(N log K)
// SC: O(K)

// Better Solution
// class Solution {
// private:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
//         while (list1 && list2) {
//             if (list1->val < list2->val) {
//                 curr->next = list1;
//                 list1 = list1->next;
//             } else {
//                 curr->next = list2;
//                 list2 = list2->next;
//             }
//             curr = curr->next;
//         }
//         curr->next = list1 ? list1 : list2;
//         return dummy->next;
//     }
//     ListNode* mergeKListsHelper(vector<ListNode*> &lists, int start, int end) {
//         if (start == end) return lists[start];
//         if (start + 1 == end) return mergeTwoLists(lists[start], lists[end]);
//         int mid = start + ((end - start) >> 1);
//         ListNode* leftList = mergeKListsHelper(lists, start, mid);
//         ListNode* rightList = mergeKListsHelper(lists, mid + 1, end);
//         return mergeTwoLists(leftList, rightList);
//     }
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.size() == 0) return nullptr;
//         return mergeKListsHelper(lists, 0, lists.size() - 1);
//     }
// };
// TC: O(N log K)
// SC: O(log K)

// Wrong Solution -> [[1,2,3],[4,5,6,7]] -> [1,2,4,3,5,6,7]
// class Solution {
// private:    
//     struct cmp {
//         bool operator()(ListNode* a, ListNode* b) const {
//             return a->val > b->val;
//         }
//     };

// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode *, vector<ListNode *>, cmp> minHeap;
//         int sz = lists.size();
//         ListNode *dummy = new ListNode(0);
//         ListNode *temp = dummy;
//         while (true) {
//             bool anyInsertion = false;
//             for (int i=0; i<sz; ++i) {
//                 if (lists[i] == nullptr) continue;
//                 anyInsertion = true;
//                 minHeap.push(lists[i]);
//                 lists[i] = lists[i]->next;
//                 if (minHeap.size() == sz) {
//                     temp->next = minHeap.top();
//                     temp = temp->next;
//                     minHeap.pop();
//                 }
//             }
//             if (!anyInsertion) break;
//         }
//         while (!minHeap.empty()) {
//             temp->next = minHeap.top();
//             temp = temp->next;
//             minHeap.pop();
//         }
//         return dummy->next;
//     }
// };