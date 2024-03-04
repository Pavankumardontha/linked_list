/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    bool ans = false;
    
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            ans=true;
            break;
            // we can start here and traverse to find the length of the loop
        }
    }
    if(ans==false)
    return 0;
    Node* temp=slow->next;
    int cnt=1;
    while(temp!=slow)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
