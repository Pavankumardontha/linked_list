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
    ListNode* deleteMiddle(ListNode* head) 
    {
        /*
        To delete a node, we need the pointer of its previous node and also the next node. 
        the pointer to the next node can easily be obtained from the current node. But 
        we need to store the pointer previous to the slow pointer.
        */
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        /*
        Now after this prev will be pointing to the previous node of the slow pointer and slow 
        pointer will be pointing to the middle element.So now we can easily delete the middle
        element to which the slow pointer is pointing to. But before this we need to check if 
        slow pointer is pointing to the head of the linkedlist.
        */
        if(slow == head)
        {
            head=NULL;
            delete slow;
            return head;
        }
        prev->next = slow->next;
        slow->next=NULL;
        delete slow;
        return head;
    }
};
