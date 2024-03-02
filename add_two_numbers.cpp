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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        // we interate untill temp1 , temp2 and carry all become 0.
        while(temp1!=NULL or temp2!=NULL or carry!=0)
        {
            int sum = 0;
            int l1_element = 0; // corresponding element of l1
            int l2_element = 0; // corresponding element of l2
            if(temp1!=NULL)
            {
                l1_element = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2!=NULL)
            {
                l2_element = temp2->val;
                temp2 = temp2->next;
            }
            // adding l1 element,l2 element and carry together
            sum = l1_element + l2_element + carry;
            int value = sum%10; // node value
            carry = sum/10; // carry value
            ListNode* node = new ListNode(value);
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
        return head;
    }
};
