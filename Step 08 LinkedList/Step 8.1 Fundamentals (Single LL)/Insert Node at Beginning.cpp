/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp=head;
        if(head==NULL)
        {
            head=new Node(x);
            return head;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        Node *temp2;
        temp2=new Node(x);
        temp->next=temp2;
        Node *pemp=head;
        return pemp;
    }
};