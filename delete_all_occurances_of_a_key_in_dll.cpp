Node * deleteAllOccurrences(Node* head, int k) 
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==k)
        {
            Node* node = temp;
            if(temp==head)
            {
                head=temp->next;
                if(head != NULL)
                head->prev=NULL;
                temp=head;
                delete node;
            }
            else
            {
                Node* prev = node->prev;
                Node* next = node->next;
                if(prev!=NULL)
                prev->next=next;
                if(next!=NULL)
                next->prev=prev;
                temp=next;
                node->next=NULL;
                node->prev=NULL;
                delete node;
            }
        }
        else
        temp=temp->next;
    }
    return head;
}
