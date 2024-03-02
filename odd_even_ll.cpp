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
    ListNode* oddEvenList(ListNode* head) 
    {
        // start from head and jump 2 steps at once
        ListNode* temp = head;
        if(head==NULL)
        return NULL;
        ListNode* new_head=NULL;
        ListNode* tail=NULL;
        while(temp!=NULL)
        {
            ListNode* node = new ListNode(temp->val);
            if(new_head==NULL)
            {
                new_head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            //check if we can take 2 steps
            if(temp->next!=NULL)
            temp = temp->next->next;
            else
            temp = NULL;
        }
        // again we start at 2nd element and repeat the same to get even index elements
        temp = head->next;
        while(temp!=NULL)
        {
            ListNode* node = new ListNode(temp->val);
            tail->next = node;
            tail = node;
            // check if we can take 2 steps or not
            if(temp->next!=NULL)
            temp=temp->next->next;
            else
            temp=NULL;
        }
        return new_head;
    }
};
