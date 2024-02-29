/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        /*
        Approach-1:
        copy data of the next node to the current node and delete the tail node
        initial case : 4->5->1->9 (we are at node 5)
        iteration-1 : 4->1->1->9
        iteration-2 : 4->1->9->9
        delete tail : 4->1->9

        OR
        Appraoch-2:
        initial case: 4->5->1->9 (we are at node 5)
        step-1: copy the next node data to the current node : 4->1->1->9
        step-2: move to the next node 4->1->1->9 ( we are at node(1) at 3rd position)
        step-3: delete the node : 4->1->9
        We will follow this approach
        */
        if(node==NULL)
        return;
        else
        {
            if(node->next!=NULL)
            {
                ListNode* temp = node->next;
                node->val = temp->val;
                node->next = temp->next;
                delete temp;
            }
            else
            delete node;
        }
    }
};
