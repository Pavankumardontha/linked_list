// GFG problem
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_set<int> s;
        Node* temp = head2;
        while(temp!=NULL)
        {
            s.insert(temp->data);
            temp = temp->next;
        }
        Node* head = NULL;
        Node* current = head;
        temp = head1;
        while(temp!=NULL)
        {
            if(s.find(temp->data)!=s.end())
            {
                Node* temp1 = new Node(temp->data);
                if(head==NULL)
                {
                    head = temp1;
                    current = head;
                }
                else
                {
                    current->next = temp1;
                    current = current->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
