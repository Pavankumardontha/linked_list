struct Node
{
    int val;
    Node* next;
    public:
        Node(int x)
        {
            val = x;
            next = NULL;
        }
};
class MyLinkedList 
{
    Node* head;
    int count;
public:
    MyLinkedList() 
    {
        head = NULL;
        count = 0;
    }
    
    int get(int index) 
    {
        if(index<0 or index>count or head == NULL)
        return -1;
        int ind=0;
        Node* temp = head;
        int ans = -1;
        while(temp != NULL)
        {
            if(ind==index)
            {
                ans = temp->val;
                break;
            } 
            temp=temp->next;
            ind++;
        }
        return ans;
    }
    
    void addAtHead(int val) 
    {
        cout<<"adding value:"<<val<<" at head"<<endl;
        Node* temp = new Node(val);
        if(head == NULL)
        head = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        count = count + 1;
    }

    void addAtTail(int val) 
    {
        cout<<"adding value:"<<val<<" at tail"<<endl;
        Node* node = new Node(val);
        if(head == NULL)
        head = node;
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
            temp = temp->next;
            temp->next = node;
        }
        count = count + 1;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index<0 or index>count)
        return;
        cout<<"adding value:"<<val<<" at index:"<<index<<endl;
        if(index == 0)
        addAtHead(val);
        else if(index == count)
        addAtTail(val);
        else
        {
            int ind=0;
            Node* temp = new Node(val);
            Node* current_node = head;
            Node* prev_node = NULL;
            while(current_node != NULL)
            {
                if(ind==index)
                {
                    prev_node->next = temp;
                    temp->next = current_node;
                    break;
                }
                else
                {
                    prev_node = current_node;
                    current_node=current_node->next;
                }
                ind++;
            }
            count = count+1;
        }
    }
    
    void deleteAtIndex(int index) 
    {

        if(index<0 or index>=count or head == NULL)
        return;
        Node* current_node = head;
        Node* prev_node = NULL;
        int ind=0;
        while(current_node != NULL)
        {
            if(ind == index)
            {
                // we should delete current node
                Node* temp = current_node;
                if(current_node == head)
                {
                    head = temp->next;
                    delete temp;
                }
                else
                {
                    prev_node->next = temp->next;
                    delete temp;
                }
                break;
            }
            else
            {
                prev_node = current_node;
                current_node = current_node->next;
            }
            ind++;
        }
        count = count - 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
