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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        /* this is very similar to add 2 large numbers using strings */
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp;
        ListNode* current=NULL;
        ListNode* head=NULL;
        while(temp1!=NULL and temp2!=NULL)
        {
            int sum = temp1->val + temp2->val + carry;
            temp = new ListNode(sum%10);
            if(head==NULL)
            {
                head = temp;
                current = head;
            }
            else
            {
                current->next = temp;
                current = current->next;
            }
            carry = sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp2!=NULL)
        {
            int sum = temp2->val + carry;
            temp = new ListNode(sum%10);
            current->next = temp;
            current = current->next;
            carry = sum/10;
            temp2 = temp2->next;
        }
        while(temp1!=NULL)
        {
            int sum = temp1->val + carry;
            temp = new ListNode(sum%10);
            current->next = temp;
            current = current->next;
            carry = sum/10;
            temp1 = temp1->next;
        }
        if(carry!=0)
        {
            temp = new ListNode(carry);
            current->next = temp;
        }
        return head;
    }
};
