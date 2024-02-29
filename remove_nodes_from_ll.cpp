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
    ListNode* removeNodes(ListNode* head) 
    {
        if(head == NULL)
        return head;
        ListNode* temp = head;

        // collect all the linked list elements into a vector
        vector<int> v;
        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();

        // find the next greater element to the right of an element using stack
        vector<int> next_greater_element(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            s.push(i);
            else
            {
                if(v[i]<v[s.top()])
                s.push(i);
                else
                {
                    while(!s.empty() and v[i]>v[s.top()])
                    {
                        next_greater_element[s.top()] = v[i];
                        s.pop();
                    }
                    s.push(i);
                }
            }

        }
        /*
         if next_greater_element[i]=-1 means we do not have element greater than ith element 
         to the right of the linked list
        */
        ListNode* current_node = head;
        ListNode* prev_node = NULL;
        int count = 0;
        while(current_node != NULL)
        {
            if(next_greater_element[count] != -1)
            {
                // we need to remove the current element
                if(current_node==head)
                {
                    ListNode* temp = current_node;
                    head = temp->next;
                    current_node = temp->next;
                    delete temp;
                }
                else
                {
                    ListNode* temp = current_node;
                    prev_node->next = temp->next;
                    current_node = temp->next;
                    delete temp;
                }
            }
            else
            {
                prev_node = current_node;
                current_node = current_node->next;
            }
            count++;
        }
        return head;
    }
};
