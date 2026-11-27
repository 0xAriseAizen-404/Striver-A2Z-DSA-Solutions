class Solution {
public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };

    Node* flatten(Node* root) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        Node* temp = root;
        while (temp != nullptr) {
            pq.push(temp);
            temp = temp->next;
        }
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        while (!pq.empty()) {
            Node* curr = pq.top();
            pq.pop();
            tail->bottom = curr;
            tail = curr;
            if (curr->bottom != nullptr) {
                pq.push(curr->bottom);
            }
            curr->next = nullptr;
        }
        tail->bottom = nullptr;
        return dummy->bottom;
    }
};