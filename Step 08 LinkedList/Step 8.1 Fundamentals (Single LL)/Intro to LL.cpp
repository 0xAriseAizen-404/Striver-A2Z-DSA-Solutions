// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node *head = new Node();
        Node *curr = head;
        
        for(auto num : arr){
            curr->next = new Node(num);
            curr = curr->next;
        }
        
        return head->next;
    }
};