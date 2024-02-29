/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head==NULL)
        return head;
        ListNode* current_node = head;
        ListNode* prev_node = NULL; // points to just immediate previous element of the current element.
        while(current_node != NULL)
        {
            if(current_node->val == val)
            {
                // we need to delete the current node
                if(current_node == head)
                {
                    // prev_node will be NULL in all the cases where current_node is head node
                    ListNode* temp = current_node;
                    head = temp->next;
                    current_node = temp->next;
                    delete temp;
                }
                else
                {
                    ListNode* temp = current_node;
                    prev_node->next=temp->next;
                    current_node = temp->next;
                    delete temp;
                }
            }
            else
            {
                prev_node = current_node;
                current_node = current_node->next;
            }
        }
        return head;
    }
};
