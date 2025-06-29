/*
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

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) 
    {
        Node* current = head;
        Node* prev = NULL;
        Node* next;
        while(current != NULL)
        {
            next = current->next;
            if(current != head)
            {
                if(prev->data == current->data)
                {
                    // remove current
                    prev->next = current->next;
                    if(current->next != NULL)
                    current->next->prev = prev;
                    current = next;
                }
                else
                {
                    prev=current;
                    current=next;
                }
            }
            else
            {
                prev = current;
                current = next;
            }
        }
        return head;
    }
};
