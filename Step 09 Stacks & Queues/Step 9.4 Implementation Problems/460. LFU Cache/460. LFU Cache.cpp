class Node {
    public:
        int key, value, cnt;
        Node *prev, *next;
        Node(int k, int v) {
            this->key = k;
            this->value = v;
            this->cnt = 1;
            prev = next = nullptr;
        }
};
class LRUCache {
    public:
        int size;
        Node *head, *tail;
        LRUCache() {
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        void addFront(Node *node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size += 1;
        }
        void removeNode(Node *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size -= 1;
        }
};
class LFUCache {
    unordered_map<int , Node*> keyNode;
    unordered_map<int, LRUCache*> freqListMap;

    int maxSizeCache;
    int minFreq;
    int currSize;
    public:
        LFUCache(int capacity) {
            maxSizeCache = capacity;
            minFreq = 0;
            currSize = 0;
        }

        void updateFreqListMap(Node *node) {
            keyNode.erase(node->key);
            freqListMap[node->cnt]->removeNode(node);
            if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
                minFreq++;
            }
            LRUCache *nextHigherFreqList;
            if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
                nextHigherFreqList = freqListMap[node->cnt + 1];
            }  else {
                nextHigherFreqList = new LRUCache();
                freqListMap[node->cnt + 1] = nextHigherFreqList;
            }
            node->cnt += 1;
            nextHigherFreqList->addFront(node);
            keyNode[node->key] = node;
        }
        
        int get(int key) {
            if (keyNode.find(key) == keyNode.end()) return -1;
            Node *node = keyNode[key];
            updateFreqListMap(node);
            return node->value;
        }
        
        void put(int key, int value) {
            if (maxSizeCache == 0) return;
            if (keyNode.find(key) != keyNode.end()) {
                Node *node = keyNode[key];
                node->value = value;
                updateFreqListMap(node);
                return;
            }
            if (currSize == maxSizeCache) {
                LRUCache *list = freqListMap[minFreq];
                Node *nodeToDelete = list->tail->prev;
                keyNode.erase(nodeToDelete->key);
                list->removeNode(nodeToDelete);
                delete nodeToDelete;
                currSize -= 1;
            }
            currSize += 1;
            minFreq = 1;
            LRUCache *listFreq;
            if (freqListMap.find(1) != freqListMap.end()) {
                listFreq = freqListMap[1];
            } else {
                listFreq = new LRUCache();
                freqListMap[1] = listFreq;
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */