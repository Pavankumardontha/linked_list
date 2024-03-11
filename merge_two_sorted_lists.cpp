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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1 != NULL and temp2 != NULL)
        {
            ListNode* node = NULL;
            if(temp1->val < temp2->val)
            {
                node = new ListNode(temp1->val);
                temp1=temp1->next;
            }
            else
            {
                node = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            if(head==NULL)
            {
                head=node;
                tail=node;
            }
            else
            {
                tail->next=node;
                tail=node;
            }
        }
        while(temp1 != NULL)
        {
            ListNode* node = new ListNode(temp1->val);
            if(head==NULL)
            {
                head=node;
                tail=node;
            }
            else
            {
                tail->next=node;
                tail=node;
            }
            temp1=temp1->next;
        }
        while(temp2 != NULL)
        {
            ListNode* node = new ListNode(temp2->val);
            if(head==NULL)
            {
                head=node;
                tail=node;
            }
            else
            {
                tail->next=node;
                tail=node;
            }
            temp2=temp2->next;
        }
        return head;
    }
};
