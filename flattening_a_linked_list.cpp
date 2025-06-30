/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

struct compare
{
    bool operator() (pair<int,Node*> x, pair<int,Node*> y)
    {
        if(x.first < y.first)
        return false;
        return true;
    }
};

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
       if(root == NULL)
       return root;
       priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,compare> pq;
       Node* current = root;
       while(current != NULL)
       {
           pq.push({current->data,current});
           current = current->next;
       }
       pair<int,Node*> temp;
       Node* head=NULL; // head of the final linked list
       Node* tail=NULL; // tail of the final linked list
       while(!pq.empty())
       {
           temp = pq.top();
           pq.pop();
           current = temp.second;
           if(current->bottom != NULL)
           {
               pq.push({current->bottom->data,current->bottom});
           }
           if(head == NULL)
           {
               head = current;
               tail = current;
           }
           else
           {
               tail->bottom = current;
               tail = current;
           }
       }
       tail->bottom = NULL;
       return head;
    }
};
