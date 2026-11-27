// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node *head= *head_ref;
        Node *curr=head;
        while(curr!=NULL){
            if(curr->data==x){
                // two important case
                if(curr->prev!=NULL){
                    curr->prev->next=curr->next;
                }
                else{
                    *head_ref=curr->next;//first node has to delete so head_ref pts. to next of curr. node
                }
                if(curr->next!=NULL){
                    curr->next->prev=curr->prev;
                }
            //  delete curr; //not compulsory
            }
            curr=curr->next;
        }
       return;
    }
};