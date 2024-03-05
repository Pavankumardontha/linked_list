/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

int solve(Node* node)
{
    if(node->next==NULL)
    {
        // we need to add 1 when we reach the tail node and ret
        int sum = node->data + 1;
        int carry = sum/10;
        int new_value=sum%10;
        node->data = new_value;
        return carry;
    }
    else
    {
        int carry = solve(node->next);
        int sum = node->data + carry;
        int new_value = sum%10;
        carry = sum/10;
        node->data = new_value;
        return carry;
    }
}


class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry = solve(head);
        if(carry!=0)
        {
            Node* node = new Node(carry);
            node->next = head;
            head=node;
        }
        return head;
    }
};
