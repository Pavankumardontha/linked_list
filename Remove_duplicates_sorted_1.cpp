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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* current_node;
        ListNode* next_node;
        current_node = head;
        while(current_node!=NULL and current_node->next!=NULL)
        {
            next_node = current_node->next;
            if(current_node->val == next_node->val)
            {
                // we need to remove the next element since current data is equal to the next data
                current_node->next = next_node->next;
                delete(next_node);
            }
            else
            current_node = current_node->next;
        }
        return head;
    }
};
