/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    Node* current_node = head;
    Node* prev_node=NULL;
    int count = 1;
    while(current_node != NULL)
    {
        if(count == x)
        {
            //we need to delete this node
            if(current_node == head)
            {
                Node* temp = current_node;
                head = temp->next;
                current_node = temp->next;
                delete temp;
            }
            else
            {
                Node* temp = current_node;
                prev_node->next=temp->next;
                current_node = temp->next;
                delete temp;
            }
            break;
        }
        else
        {
            prev_node = current_node;
            current_node = current_node->next;
        }
        count++;
    }
    return head;
}
