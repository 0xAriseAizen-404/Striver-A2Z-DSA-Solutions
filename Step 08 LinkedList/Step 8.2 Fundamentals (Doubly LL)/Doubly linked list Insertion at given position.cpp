/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
    if(head == NULL) return ;
   int count=-1;
   Node * temp= head;
   while(temp->next!=NULL){
       count++;
       if(count ==pos)break;
       temp=temp->next;
       
   }
   if(temp->next ==NULL) ++count;
   Node * newnode =new Node(data);
   Node *nextnode=temp->next;
   if(nextnode == NULL && count==pos){//insertion after tail
       newnode->prev=temp;
       temp->next =newnode;
       return ;
   }
   
   temp->next=newnode;
   newnode->prev=temp;
   nextnode->prev=newnode;
   newnode->next=nextnode;
   return ;
}