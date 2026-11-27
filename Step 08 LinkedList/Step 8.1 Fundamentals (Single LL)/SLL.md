### **1. Node structure (common prerequisite)**

```
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
```

### **2. Traversal in Linked List**

```
void traverse(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

### **3. Deletion in Linked List**

General deletion is covered by the specific deletion operations below. No separate function is necessary.

### **4. Insertion in Linked List**

General insertion is covered by the specific insertion operations below.

### **5. Deletion of the Head**

```
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}
```

### **6. Deletion of the Tail**

```
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}
```

### **7. Deletion of the Kth Element (1-based)**

```
Node* deleteKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return head;

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;

    return head;
}
```

### **8. Delete the Element with Value X**

Deletes the **first occurrence** of X.

```
Node* deleteValue(Node* head, int x) {
    if (head == nullptr) return nullptr;

    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != x) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return head;

    Node* delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;

    return head;
}
```

### **9. Insertion at the Head**

```
Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;

    return newNode;
}
```

### **10. Insertion at the Tail**

```
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) return newNode;

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}
```

### **11. Insertion at the Kth Position (1-based)**

```
Node* insertKth(Node* head, int val, int k) {
    if (k <= 0) return head;

    if (k == 1) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return head;

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
```

### **12. Insertion Before the Value X**

Inserts before the **first occurrence** of X.

```
Node* insertBeforeValue(Node* head, int val, int x) {
    if (head == nullptr) return head;

    if (head->data == x) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != x) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return head;

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
```

### **13. Find the Length of Linked List**

```
int lengthOfLL(Node* head) {
    int count = 0;

    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}
```

### **14. Search in Linked List**

Returns `true` if the value exists.

```
bool searchInLL(Node* head, int x) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == x) return true;
        temp = temp->next;
    }

    return false;
}
```

## **Complexity Reference**

Let `N` be the number of nodes.

| Operation       | Time Complexity |
| --------------- | --------------- |
| Traversal       | O(N)            |
| Delete Head     | O(1)            |
| Delete Tail     | O(N)            |
| Delete Kth      | O(N)            |
| Delete Value X  | O(N)            |
| Insert Head     | O(1)            |
| Insert Tail     | O(N)            |
| Insert Kth      | O(N)            |
| Insert Before X | O(N)            |
| Find Length     | O(N)            |
| Search          | O(N)            |

**Important observations:**

1. Head insertion and deletion take O(1) because we directly modify the head pointer.
2. Tail insertion and deletion take O(N) because we need to traverse to the last or second-last node.
3. Kth insertion and deletion take O(N) because we need to reach the previous node.
4. If you maintain a separate tail pointer, tail insertion can be reduced to O(1).

**One important convention:** All Kth-position operations above use 1-based indexing, matching the usual Striver A2Z Linked List problems.
