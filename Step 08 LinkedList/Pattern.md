8.3.1 - Add Two Numbers -> take two tails and traverse them while adding both x->val and taking a carry also x%10 and x/10.
8.3.2 - Odd and Even lists together -> take two instances indicating 0th index odd and 1st index even, traverse while adding the nodes to respective lists
8.3.3 - sort 0s 1s 2s - take three different lists and traverse the list if the val is 0 or 1 or 2, add it to respective list
8.3.4 - remove nth node from end - first traverse for first n-1 nodes, get the n-1 node from frist to reflect it from end, then traverse fast and slow together, so that fast go to the end, then remove the slow and add it to slow->next->next
8.3.5 - reverse linked list -> next, curr, prev

8.4.1 - Add 1 to the list
8.4.2 - middle of the linked list -> use Slow and Fast Pointer Approach
8.4.3 - delete middle node -> use Slow and Fast Pointer Approach
8.4.4 - Palindrome ll -> get to Mid Point, reverse the second half of list, traverse both & compare, reverse the second half again to get it right
8.4.5 - Insertion of two tails -> traverse both lists, once reach an end, start it from the other head, eventually meet at point, return that insertion
8.4.6 - LL Cyle 1 -> use Slow and Fast Pointer Approach
8.4.7 - LL Cycle 2 -> use Slow and Fast Pointer Approach, a little bit tricky, but can be done
8.4.8 - Length of Loop -> use Slow and Fast Pointer Approach

8.5.1 - Reverse K-Group Nodes -> Get the K Nodes of the list, reverse them, add it to dummy, then get next k nodes, same
8.5.2 - Rotate LL -> Make a loop at the tail, move k positions from tail, that's the new head
8.5.3 - Merge K Sorted List -> Approach 1: can use Merge Sort Approach but for lists here
Approach 2: use MinHeap with cmp, first insert all the heads, get the minHead and add it to dummy, insert next node of that minHead into minHeap.
8.5.4 - Flatten LL -> use MinHeap, traverse the list with next pointer and add them into heap, then pop the minHeap, traverse bottom pointers, push the bottom pointer, and make next pointer null, one node at a time, don't traverse all the bottom pointers, push one at a time
8.5.5 - Sort List -> get Mid Node by Slow and Fast Pointer Approach, use Merge Sort for Linked Lists here
8.5.6 - Copy List with Random Pointer -> use Mapping of (Node, Node)

8.6.1 - Delete all Occurances in DLL -> just traverse and delete the references
8.6.2 - Remove duplicates from sorted DLL -> just traverse and delete the references
8.6.3 - Find pairs of given sum in DLL -> get the tail, use left and right pointer appraoch

Linked List -> Patterns need to focus on ->

1. Slow and Fast Pointer Approach &&&& Its Add Ons
2. Merge Sort for Linked Lists
3. Reverse the list & Traverse the list
4. Mid Pointer or Node using Slow and Fast Pointer Approach
