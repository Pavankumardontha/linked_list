/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        /*
        1) Interleave copied nodes with original nodes. For each node in the original linked list, 
        create a copy and insert it immediately after the original node. The modified list will look 
        like:
        original(n1) → copy(n1) → original(n2) → copy(n2) → ...
        2) Assign random pointers to copied nodes. Traverse the updated list from the head. Since nodes 
        are interleaved, every even-indexed node is an original node and every odd-indexed node is its copy.
        While traversing:
        For each original node, store its random pointer.       
        3) Assign this stored random to its corresponding copy node (i.e., node->random = random)
        4) Separate the copied list from the original. Traverse the list again and restore the original 
        list by skipping over the copy nodes. At the same time, extract the copied nodes to form a new list.
        This restores the original list to its initial structure and builds the deep copy.
        */
        
        // add copy node to the next of each original node
        Node* current = head;
        Node* temp;
        Node* next;
        while(current != NULL)
        {
            next = current->next;
            temp = new Node(current->val);
            current->next=temp;
            temp->next=next;
            current = next;
        }
        
        // do steps 2,3
        current = head;
        Node* random;
        int index = 0;
        // fill the random nodes in the copy nodes
        while(current != NULL)
        {
            next = current->next;
            if(index%2==0)
            random = current->random;
            else
            {
                if(random != NULL)
                current->random = random->next;
                else
                current->random = NULL;
            }
            current = next;
            index++;
        }

        // remove copy nodes to form a seperate ll and keep only original nodes in the original ll
        current = head;
        Node* copy_nodes_head=NULL;
        index=0;
        while(current != NULL)
        {
            next = current->next;
            if(index%2==0)
            {
                // original node
                current->next = current->next->next;
            }
            else
            {
                //copy node
                if(copy_nodes_head == NULL)
                copy_nodes_head = current;
                if(current->next != NULL)
                current->next = current->next->next;
                else
                current->next = NULL;
            }
            current=next;
            index++;
        }
        return copy_nodes_head;
    }
};
