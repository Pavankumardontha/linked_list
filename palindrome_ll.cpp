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

void reverseLinkedList(ListNode* &head)
{
    ListNode* prev=NULL;
    ListNode* current=head;
    ListNode* next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head=prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        /*
        Method 1: Using a Stack
        1) Traverse the linked list and push all the node values onto a stack.
        2) Then, traverse the list again from the beginning.
        3) For each node, compare its value with the top element of the stack:
        4) If they are equal, continue traversing and pop the stack.
        5) If any mismatch is found, the list is not a palindrome.
        6) If you successfully reach the end of the list with all comparisons matching, the list is a palindrome.
        Time Complexity: O(2·N)
        Space Complexity: O(N)

        Optimized Approach (without using extra space):
        1) Use slow and fast pointers to find the middle of the linked list.
        2) Reverse the second half of the list starting from the midpoint.
        3) Compare the nodes from the beginning and the reversed second half one by one.
        4) (Optional) Restore the list to its original form if needed.
        Time Complexity: O(N)
        Space Complexity: O(1) — No additional space is used apart from a few pointers.
        */

        if(head == NULL or head->next == NULL)
        return true;
        else
        {
            ListNode* s = head;
            ListNode* f = head;
            /*
            ll = 1 2 3 4 NULL 
            (1,1) -> (2,3) -> (3,NULL) so slow pointer stops at the starting of the linkedlist we need to reverse

            l1 = 1 2 3 4 5 NULL (we compare first 2 elements with the last 2 elements)
            (1,1) -> (2,3) -> (3,5) 
            */
            int no_of_elements_to_compare=0;
            while(f!=NULL and f->next!=NULL)
            {
                s=s->next;
                f=f->next->next;
                no_of_elements_to_compare++;
            }
            /*
            if f==null then the linked list is of even length and the head of the second half of the linked list is s
            if f->next=null then the linked list is of odd length and the head of the second half of the linked list is s->next
            */
            ListNode* head2;
            if(f==NULL)
            head2=s;
            else
            head2=s->next;
            reverseLinkedList(head2);

            int comparisions=0;
            ListNode* temp1 = head;
            ListNode* temp2 = head2;
            while(comparisions<no_of_elements_to_compare)
            {
                if(temp1->val!= temp2->val)
                return false;
                else
                {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    comparisions++;
                }
            }
            return true;
        } 
    }
};
