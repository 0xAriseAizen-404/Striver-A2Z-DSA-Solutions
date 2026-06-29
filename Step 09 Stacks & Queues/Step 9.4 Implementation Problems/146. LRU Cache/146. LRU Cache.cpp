// https://leetcode.com/problems/lru-cache/

class Node {
public:
    int key, value;
    Node *prev, *next;
    Node (int k, int v) {
        this->key = k;
        this->value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    map<int, Node*> mpp;
    int capacity;
    Node *head;
    Node *tail;

    LRUCache(int cap) {
        this->capacity = cap;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void deleteNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node *node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
            if (mpp.find(key) != mpp.end()) {
            Node *node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        if (mpp.size() == capacity) {
            Node *lru = tail->prev;
            deleteNode(lru);
            mpp.erase(lru->key);
            delete lru;
        }
        Node *newNode = new Node(key, value);
        insertAfterHead(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */