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


/* APPROACH - 1 Using extra space */
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


/*APPROACH-2 Using contant space very important solution */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        /*
        Merging 2 sorted linked lists without using extra space
        */
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        if(temp1 == NULL)
        return temp2;
        if(temp2 == NULL)
        return temp1;
        while(temp1 != NULL and temp2 != NULL)
        {
            if(head==NULL)
            {
                if(temp1->val <= temp2->val)
                {
                    head=temp1;
                    tail=temp1;
                    temp1 = temp1->next;
                }
                else
                {
                    head=temp2;
                    tail=temp2;
                    temp2 = temp2->next;
                }

            }
            else
            {
                if(temp1->val <= temp2->val)
                {
                    // we need to assign temp1 to tail and move temp1 to next
                    tail->next=temp1;
                    tail=temp1;
                    temp1=temp1->next;
                }
                else
                {
                    // assign temp2 to tail and move temp2 to next node
                    tail->next = temp2;
                    tail=temp2;
                    temp2=temp2->next;
                }
            }
        }
        while(temp1!=NULL)
        {
            tail->next=temp1;
            tail=temp1;
            temp1=temp1->next;
        }
        while(temp2 != NULL)
        {
            tail->next=temp2;
            tail=temp2;
            temp2=temp2->next;
        }
        tail->next=NULL;
        return head;
    }
};


