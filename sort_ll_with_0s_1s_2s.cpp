/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

void addNode(Node* &head, Node* &tail,Node* &node)
{
    if(head==NULL)
    {
        head=node;
        tail=node;
    }
    else
    {
        tail->next=node;
        tail=node;
    }
}
class Solution {
  public:
    Node* segregate(Node* head) 
    {
        /*
        Method-1:- Keep the counts of 0,1 and 2's as 
        c0,c1 and c2. Traverse the linked list and updates the
        counts accordingly. After we got the counts, we can again
        traverse the linked list and place c0 0's , c1 1's and 
        c2 2's in the linked list.
        Time complexity : O(2n)
        Space : o(1)
        
        Can we do better ?? - yes
        Method-2:- we break down the linked list into 3 linked 
        lists. 
        First linked list only containing 0's
        second linked list only containing 1's
        and thir linked list only containing 2's
        and then we will attach the 
        tail1->tail2->tail3
        */
        if(head == NULL or head->next == NULL)
        return head;
        Node* current = head;
        Node* h0=NULL; // head of linked list with node 0's
        Node* h1=NULL; // head of linked list with node 1's
        Node* h2=NULL; // head of linked list with node 2's
        Node* t0=NULL;
        Node* t1=NULL;
        Node* t2=NULL;
        while(current != NULL)
        {
            if(current->data == 0)
            addNode(h0,t0,current);
            else if(current->data==1)
            addNode(h1,t1,current);
            else
            addNode(h2,t2,current);
            current = current->next;
        }
        head=NULL; // head of the combined linked list
        Node* tail=NULL; // tail of the combiner linked list
        if(h0!=NULL)
        {
            head=h0;
            tail=t0;
            if(h1!=NULL)
            {
                tail->next=h1;
                tail = t1;
            }
            if(h2!=NULL)
            {
                tail->next=h2;
                tail=t2;
            }
        }
        else if(h1!=NULL)
        {
            head=h1;
            tail=t1;
            if(h2!=NULL)
            {
                tail->next=h2;
                tail=t2;
            }
        }
        else if(h2!=NULL)
        {
            head=h2;
            tail=t2;
        }
        tail->next = NULL;
        return head;
    }
};
