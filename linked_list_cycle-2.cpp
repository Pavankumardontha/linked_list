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
    ListNode *detectCycle(ListNode *head) 
    {
        /*
        Find the collision point where both fast and slow pointer hit. After that start the
        slow pointer from the head and move to the next(single step). Start the fast pointer from the 
        collision point and move to the next(single step).The point of collision will give
        us the node where the cycle begins.
        */
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasLoop = false;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                hasLoop = true;
                break;
            }
        }
        if(hasLoop==false)
        return NULL;
        /*
        now start the slow pointer from head and fast pointer from where it is. The moment
        they collide , that will be the cycle begin point.
        */
        slow=head;
        while(slow!=NULL)
        {
            if(slow==fast)
            return slow;
            else
            {
                slow=slow->next;
                fast=fast->next; //NOTE: here we increment by the fast pointer by 1
            }
        }
        return NULL;
    }
};
