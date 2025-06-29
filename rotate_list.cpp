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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next == NULL or k==0)
        return head;
        ListNode* current = head;
        int n = 0; // length of the linked list
        while(current != NULL)
        {
            n++;
            current = current->next;
        }
        k = k%n;
        if(k==0)
        return head;
        // move till n-kth node. That will be the last node after rotation and its next node will be the first node
        current = head;
        cout<<n<<endl;
        for(int i=1;i<n-k;i++)
        {
            current=current->next;
        }
        ListNode* next = current->next;
        current->next = NULL;
        current = next;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = head;
        head = next;
        return head;
    }
};
