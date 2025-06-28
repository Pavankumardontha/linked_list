/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        /*
        Approach:
        1) Find the lengths of both linked lists. Difference of lengths is important
        2) If the lengths are equal, start comparing nodes from the heads of both lists.
        3) If one list is longer than the other (say, lengths are l1 and l2 with l1 < l2),
        move l2 - l1 steps forward in the longer list to align both lists at the same level.
        4) Then, compare the nodes of both lists one by one from this aligned position.
        */
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1==l2)
            {
                // same length case
                return l1;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1== NULL and l2==NULL)
        return NULL;
        else if(l1==NULL)
        {
            // l2 is larger than l1
            int diff = 0; // difference in lengths
            while(l2!=NULL)
            {
                l2=l2->next;
                diff++;
            }
            // now move l2 by diff and then start comparing 
            l1=headA;
            l2=headB;
            for(int i=0;i<diff;i++)
            l2=l2->next;
            while(l1 != NULL and l2 != NULL)
            {
                if(l1==l2)
                return l1;
                l1=l1->next;
                l2=l2->next;
            }
            return NULL;
        }
        else
        {
            // l1 is larger than l2
            int diff=0;
            while(l1!=NULL)
            {
                l1=l1->next;
                diff++;
            }
            l1=headA;
            l2=headB;
            for(int i=0;i<diff;i++)
            l1=l1->next;
            while(l1!=NULL and l2!=NULL)
            {
                if(l1==l2)
                return l1;
                l1=l1->next;
                l2=l2->next;
            }
            return NULL;
        }
    }
};
