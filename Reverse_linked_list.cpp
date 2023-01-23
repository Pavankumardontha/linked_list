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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(current!=NULL)
        {
            // extract the next node connected to our current node
            next = current->next;
            // change the link of the current node to previous node
            current->next = prev;
            // change the previous and current
            prev = current;
            current = next;  
        }
        // at the end prev points to last node and current becomes NULL.We will update the head
        head = prev;
        return head;
        
    }
};
