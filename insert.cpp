class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) 
    {
        Node* temp = new Node(x);
        if(head != NULL)
        temp->next = head;
        head=temp;
        return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  
    {
       Node* temp = new Node(x);
       if(head!=NULL)
       {
           Node* current_node = head;
           Node* next_node = head->next;
           while(next_node != NULL)
           {
               current_node = next_node;
               next_node = next_node->next;
           }
           // our current node will be the tail node
           current_node->next = temp;
       }
       else
       head = temp;
       return head;
    }
};
