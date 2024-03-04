struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node* cur=head;
        Node* prev=NULL;
        while(cur!=NULL)
        {
            if(prev==NULL)
            {
                //first element
                prev=cur;
                cur=cur->next;
                prev->next=NULL; // this becomes the tail node
            }
            else
            {
                // next pointer of current node should point to prev node
                // prev pointer of prev node should point to current node
                Node* temp = cur;
                cur=cur->next;
                temp->next = prev;
                prev->prev = temp;
                prev=temp;
            }
        }
        head=prev;
        head->prev=NULL;
        return head;
    }
};

