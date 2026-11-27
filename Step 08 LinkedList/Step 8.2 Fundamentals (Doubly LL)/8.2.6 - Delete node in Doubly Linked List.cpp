/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
         int count = 1;
        Node* temp = head;

        while(count != x){
            temp = temp -> next;
            count++;
        }
        
        if(temp -> prev == NULL){
            temp = temp -> next;
            head = temp;
            temp -> prev = NULL;
        }
        
        else if(temp -> next == NULL){
            Node* nd = temp -> prev;
            nd -> next = NULL;
            temp -> prev = NULL;
        }
        
        else{
            Node* pr = temp -> prev;
            Node* nx = temp -> next;
            
            temp -> next = pr -> next -> next;
            temp -> prev = nx -> prev -> prev;
  
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
            
            temp -> next == NULL;
            temp -> prev == NULL;
  
        }
        return head;
    }
};