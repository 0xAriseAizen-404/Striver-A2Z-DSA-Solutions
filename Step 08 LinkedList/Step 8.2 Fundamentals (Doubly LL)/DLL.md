For **Doubly Linked List (DLL)**, Introduction doesn't need a separate function. We just need the node structure.

All functions below use the standard DLL structure and assume **1-based indexing for Kth position**.

### **1. Node Structure**

```
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
```

### **2. Convert Array to Doubly Linked List**

```
Node* convertArrayToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* curr = new Node(arr[i]);
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }

    return head;
}
```

### **3. Delete Tail of Doubly Linked List**

```
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newTail = tail->prev;
    newTail->next = nullptr;

    delete tail;

    return head;
}
```

### **4. Delete Kth Element of Doubly Linked List**

```
Node* deleteKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    Node* curr = head;

    for (int i = 1; curr != nullptr && i < k; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) return head;

    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {
        head = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    delete curr;

    return head;
}
```

### **5. Removing Given Node in Doubly Linked List**

Assumption: Given node is not the head.

```
void deleteNode(Node* node) {
    if (node == nullptr) return;

    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }

    node->next = nullptr;
    delete node;
}
```

### **6. Insert Node Before Head**

```
Node* insertBeforeHead(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    return newNode;
}
```

### **7. Insert Node Before Tail**

```
Node* insertBeforeTail(Node* head, int val) {
    if (head == nullptr) return new Node(val);

    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* newNode = new Node(val);

    newNode->prev = tail->prev;
    newNode->next = tail;

    if (tail->prev != nullptr) {
        tail->prev->next = newNode;
    }
    else {
        head = newNode;
    }

    tail->prev = newNode;

    return head;
}
```

### **8. Insert Node Before Kth Node (1-based)**

```
Node* insertBeforeKth(Node* head, int val, int k) {
    if (k <= 0) return head;

    if (k == 1) return insertBeforeHead(head, val);

    Node* curr = head;

    for (int i = 1; curr != nullptr && i < k; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) return head;

    Node* newNode = new Node(val);

    Node* prevNode = curr->prev;

    newNode->prev = prevNode;
    newNode->next = curr;

    prevNode->next = newNode;
    curr->prev = newNode;

    return head;
}
```

### **9. Insert Before Given Node**

```
void insertBeforeNode(Node* node, int val) {
    if (node == nullptr) return;

    Node* newNode = new Node(val);

    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev != nullptr) {
        node->prev->next = newNode;
    }

    node->prev = newNode;
}
```

### **10. Delete Head of Doubly Linked List**

```
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;

    return head;
}
```

### **11. Reverse a Doubly Linked List**

```
Node* reverseDLL(Node* head) {
    if (head == nullptr) return nullptr;

    Node* curr = head;
    Node* prevNode = nullptr;

    while (curr != nullptr) {
        prevNode = curr->prev;
        curr->prev = curr->next;
        curr->next = prevNode;

        curr = curr->prev;
    }

    return prevNode->prev;
}
```

## **Complexity Reference**

Let `N` be the number of nodes.

| Operation                | Time Complexity |
| ------------------------ | --------------- |
| Convert Array to DLL     | O(N)            |
| Delete Tail              | O(N)            |
| Delete Kth               | O(N)            |
| Remove Given Node        | O(1)            |
| Insert Before Head       | O(1)            |
| Insert Before Tail       | O(N)            |
| Insert Before Kth        | O(N)            |
| Insert Before Given Node | O(1)            |
| Delete Head              | O(1)            |
| Reverse DLL              | O(N)            |

**Important concepts to remember:**

- In DLL, every insertion/deletion must maintain both `next` and `prev`.
- If you already have a node pointer, insertion before it and deletion of it take O(1).
- Deleting a given node assumes you have access to its previous node or that the node is not the head.
- Operations that require finding a node take O(N).