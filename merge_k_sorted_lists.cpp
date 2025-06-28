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


 /*
 space complexity : O(K) where K is the no. of linked lists to be merged. This is because at max we are storing
 K elements in the min heap
 time complexity : KlogK + KNlogK
 */
 struct compare
 {
    // operator for min heap 
    bool operator()(ListNode* x, ListNode* y)
    {
        // basic functionality of operator:- return false if x comes first and true if y comes first.
        if(x->val<=y->val)
        {
            // x comes first 
            return false;
        }
        else
        {
            // y comes first
            return true;
        }
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // lists[i] contains the head node of ith linkedin list
        ListNode* head = NULL; // head node of the merged list
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        // push all the head nodes of each list into the priority queue
        for(int i=0;i<lists.size();i++)
        {
            // if pushing the head node of a list check if its NULL or not
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        /*
        we pop the last element and add the node into the merged linked list. Lets say we have popped a node
        from the queue that belongs to list[i] then we add the second element into the priority queue from
        that list[i]. We repeat the same for rest of the elements.
        */
        ListNode* current_node;
        ListNode* prev_node=head;
        while(!pq.empty())
        {
            current_node = pq.top();
            pq.pop();
            if(head == NULL)
            {
                head = current_node;
            } 
            if(current_node->next != NULL)
            pq.push(current_node->next);
            current_node->next = NULL;
            if(prev_node != NULL)
            prev_node->next = current_node;
            prev_node = current_node;
        }
        return head;
    }
};
