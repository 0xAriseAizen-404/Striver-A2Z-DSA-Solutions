/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node *zeros=new Node(-1);
        Node *ones=new Node(-1);
        Node *twos=new Node(-1);
        Node *curr=head;
        Node *headones=ones;
        Node *headtwos=twos;
        Node *headzeros=zeros;
        while(curr!=NULL){
            if(curr->data==0){
                zeros->next=curr;
                zeros=zeros->next;
            }
            if(curr->data==1){
                ones->next=curr;
                ones=ones->next;
            }
            if(curr->data==2){
                twos->next=curr;
                twos=twos->next;
            }
            curr=curr->next;
        }
        zeros->next=(headones->next!=NULL) ? headones->next : headtwos->next;
        ones->next=headtwos->next;
        twos->next=NULL;
        head=headzeros->next;
        return head;
    }
};
