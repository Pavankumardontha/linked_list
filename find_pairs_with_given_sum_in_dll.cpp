// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) 
    {
        /*
        we use 2 pointers technique here.
        one pointer starting from the left and the other pointer
        strating from the end.
        */
        Node* tail=NULL;
        Node* current=head;
        while(current->next != NULL)
        current = current->next;
        tail = current;
        
        vector<pair<int,int>> ans;
        Node* start = head;
        Node* end = tail;
        while(start != end)
        {
            if(start->data + end->data == target)
            {
                ans.push_back({start->data,end->data});
                start=start->next;
                // there is a possibility that here start and end both are equal
                if(start == end)
                break;
                end = end->prev;
            }
            else if(start->data + end->data < target)
            {
                // we need to increase the sum so move start pointer
                start=start->next;
            }
            else
            end = end->prev;
        }
        return ans;
        
    }
};
