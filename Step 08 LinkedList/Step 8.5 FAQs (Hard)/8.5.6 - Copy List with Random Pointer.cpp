/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapp;
        int i = 0;
        Node* temp = head;
        while (temp) {
            mapp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            mapp[temp]->next = mapp[temp->next];
            mapp[temp]->random = mapp[temp->random];
            temp = temp->next;
        }
        return mapp[head];
    }
};