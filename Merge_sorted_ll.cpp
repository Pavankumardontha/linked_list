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
        // this is very much similar to merge two sorted arrays
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* head; // head of new linked list
        ListNode* current; // last node address in the new linked list
        ListNode* temp; // temporary node

        /*checking if any linked list is NULL or not */
        if(t1==NULL and t2!=NULL)
        return t2;
        if(t1!=NULL and t2==NULL)
        return t1;
        if(t1==NULL and t2==NULL)
        return NULL;

        if(t1->val<t2->val)
        {
            head = new ListNode(t1->val);
            t1 = t1->next;
        }
        else
        {
            head = new ListNode(t2->val);
            t2 = t2->next;
        }
        current = head;
        while(t1!=NULL and t2!=NULL)
        {
            if(t1->val < t2->val)
            {
                temp = new ListNode(t1->val);
                current->next = temp;
                current = current->next;
                t1 = t1->next;
            }
            else
            {
                temp = new ListNode(t2->val);
                current->next = temp;
                current = current->next;
                t2 = t2->next;
            }
        }
        while(t1!=NULL)
        {
            temp = new ListNode(t1->val);
            current->next = temp;
            current = current->next;
            t1 = t1->next;
        }
        while(t2!=NULL)
        {
            temp = new ListNode(t2->val);
            current->next = temp;
            current = current->next;
            t2 = t2->next;
        }
        return head;
    }
};
