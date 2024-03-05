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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* prev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        /*
        We move the fast pointer first n times from the start. After this, we move the fast and
        slow pointer by one steep each. By the time fast pointer becomes NULL , the slow pointer
        points to the node that has to be deleted. Since we are deleting the node, we need to 
        also track the previous node address of the node to be deleted.
        */
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
            if(fast==NULL)
            break;
        }
        while(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head)
        {
            head=head->next;
            slow->next=NULL;
            delete slow;
        }
        else
        {
            prev->next=slow->next;
            delete slow;
        }
        return head;
    }
};
