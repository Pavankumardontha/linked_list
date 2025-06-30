/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


pair<Node*,Node*> explore(Node* &current)
{
    /*
    1) explore current node
    2) explore child node of the current node
    3) explore next node of the current node
    */
    pair<Node*,Node*> child={NULL,NULL};
    pair<Node*,Node*> next={NULL,NULL};
    if(current->child != NULL)
    child = explore(current->child);
    if(current->next != NULL)
    next = explore(current->next);

    // after explore we will get the head and tail nodes of each exploration.
    Node* head = current;
    Node* tail = current;
    if(child.first != NULL)
    {
        tail->next = child.first;
        child.first->prev = tail;
        tail = child.second;
    }
    if(next.first != NULL)
    {
        tail->next = next.first;
        next.first->prev = tail;
        tail = next.second;
    }
    current->child=NULL; // given in the problem to make the child pointers of all the nodes to NULL
    return {head,tail};
}


class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(head == NULL)
        return head;
        pair<Node*,Node*> ans = explore(head); // returns the head and tail of the final linked list
        return ans.first; // head of the final doubly linked list
    }
};
