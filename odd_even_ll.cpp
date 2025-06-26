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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next == NULL)
        return head;
        int current_ind = 0;
        ListNode* current = head;
        ListNode* evenhead=NULL;
        ListNode* oddhead=NULL;
        ListNode* eventail=NULL;
        ListNode* oddtail=NULL;
        while(current != NULL)
        {
            if(current_ind%2 == 0)
            {
                // even index
                if(evenhead==NULL)
                {
                    evenhead=current;
                    eventail=current;
                }
                else
                {
                    eventail->next=current;
                    eventail=current;
                }
            }
            else
            {
                // odd index
                if(oddhead==NULL)
                {
                    oddhead = current;
                    oddtail = current;
                }
                else
                {
                    oddtail->next = current;
                    oddtail = current;
                }
            }
            current_ind++;
            current = current->next;
        }
        eventail->next = oddhead;
        oddtail->next = NULL;
        return evenhead;
    }
};






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
