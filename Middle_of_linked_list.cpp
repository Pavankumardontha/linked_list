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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow_ptr=head;
        ListNode* fast_ptr=head;
        while(slow_ptr!=NULL and fast_ptr!=NULL and fast_ptr->next!=NULL)
        {
            /* 
            At each step slow pointer will increment by 1 and fast pointer by 2
            if slow_ptr!=NULL then slow_ptr->next will EXIST
            if fast_ptr!=NULL then fast_ptr->next will EXIST
            if fast_ptr->next!=NULL then fast_ptr->next->next will EXIST
            */
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr;
    }
};
