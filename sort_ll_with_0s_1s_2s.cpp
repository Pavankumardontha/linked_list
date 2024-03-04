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
    Node* segregate(Node *head) 
    {
        // traverse the entire linked list and break it down into 3 linked lists each having only 0's,1's or 2's
        Node* temp = head;
        Node* zerohead=NULL;
        Node* zerotail=NULL;
        Node* onehead=NULL;
        Node* onetail=NULL;
        Node* twohead=NULL;
        Node* twotail=NULL;
        while(temp!=NULL)
        {
            Node* node = new Node(temp->data);
            if(temp->data==0)
            {
                if(zerohead==NULL)
                {
                    zerohead=node;
                    zerotail=node;
                }
                else
                {
                    zerotail->next=node;
                    zerotail=node;
                }
            }
            else if(temp->data==1)
            {
                if(onehead==NULL)
                {
                    onehead=node;
                    onetail=node;
                }
                else
                {
                    onetail->next=node;
                    onetail=node;
                }
            }
            else
            {
                if(twohead==NULL)
                {
                    twohead=node;
                    twotail=node;
                }
                else
                {
                    twotail->next=node;
                    twotail=node;
                }
            }
            temp=temp->next;
        }
        // after traversing we will have 3 linked lists. We need to now connect them.
        
        Node* final_head=NULL;
        Node* final_tail=NULL;
        if(zerohead!=NULL)
        {
            final_head=zerohead;
            final_tail=zerotail;
        }
        if(onehead!=NULL)
        {
            if(final_head==NULL)
            {
                final_head=onehead;
                final_tail=onetail;
            }
            else
            {
                final_tail->next=onehead;
                final_tail=onetail;
            }
        }
        if(twohead!=NULL)
        {
            if(final_head==NULL)
            {
                final_head=twohead;
                final_tail=twotail;
            }
            else
            {
                final_tail->next=twohead;
                final_tail=twotail;
            }
        }
        return final_head;
    }
};
