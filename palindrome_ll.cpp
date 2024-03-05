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

ListNode* reverseLinkedList(ListNode* h)
{
    if(h==NULL or head->next==NULL)
    return h;
    ListNode* prev = NULL;
    ListNode* cur = h;
    while(cur!=NULL)
    {
        if(prev==NULL)
        {
            prev=cur;
            cur=cur->next;
            prev->next=NULL;
        }
        else
        {
            ListNode* next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        /*
        Here also We will have 2 pointers slow and fast same like before. We reverse the 
        linked list from slow pointer onwards
        */
        if(head==NULL or head->next==NULL)
        return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //we have to reverse the linked list from slow pointer
        ListNode* reverse_head = reverseLinkedList(slow);
        ListNode* temp1 = head; // first half head
        ListNode* temp2 = reverse_head; // head of the reversed second half
        while(temp1!=NULL and temp2!=NULL)
        {
            if(temp1->val != temp2->val)
            return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
