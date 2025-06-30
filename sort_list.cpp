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

ListNode* mergeLL(ListNode* &l1, ListNode* &l2)
{
    if(l1 == NULL and l2==NULL)
    return l1;
    else if(l1 == NULL)
    return l2;
    else if(l2==NULL)
    return l1;
    else
    {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL and temp2!=NULL)
        {
            if(temp1->val < temp2->val )
            {
                if(head == NULL)
                {
                    head = temp1;
                    tail = temp1;
                }
                else
                {
                    tail->next = temp1;
                    tail = temp1;
                }
                temp1=temp1->next;
            }
            else
            {
                if(head == NULL)
                {
                    head = temp2;
                    tail = temp2;
                }
                else
                {
                    tail->next = temp2;
                    tail = temp2;
                }
                temp2 = temp2->next;
            }
        }
        while(temp1 != NULL)
        {
            tail->next = temp1;
            tail = temp1;
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            tail->next = temp2;
            tail=temp2;
            temp2=temp2->next;
        }
        tail->next = NULL;
        return head;
    }

}
ListNode* mergesort(ListNode* &head)
{
    // this returns the new head of the sorted ll
    if(head == NULL or head->next==NULL)
    return head;

    // if head is not equal to tail , it means we have more than one element and so we have to break them up
    // use fast and slow pointers to find the middle element
    ListNode* s=head;
    ListNode* prev;
    ListNode* f=head;
    while(f!=NULL and f->next!=NULL)
    {
        prev = s;
        s=s->next;
        f=f->next->next;
    }
    /*
    (0,1,2,3,NULL) -> (0,0)->(1,2) -> (2,NULL)
    */
    prev->next=NULL;
    ListNode* left_head = mergesort(head); // head will be the starting node of left ll
    ListNode* right_head = mergesort(s); // s will be the starting node of the right ll
    head = mergeLL(left_head,right_head); // merge the 2 sorted lls and return the head
    return head;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        return mergesort(head);
    }
};

/*
Space complexity : O(1) exlcuding recursion call stack
Time complexity : The height of the tree is logN here also. At each step , we find the middle and merge the 2 lls.
So time complexity = logN*(N/2 + N) ~ NlogN
O(N) for merging 
O(N/2) for finding the middle of the ll
*/
