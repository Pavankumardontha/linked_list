class Node
{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int x)
    {
        val=x;
        next=NULL;
        prev=NULL;
    }
};

class MyLinkedList 
{
    int count; // size of doubly-linked list
    Node* head;
    Node* tail;
public:
    MyLinkedList() 
    {
        head=NULL;
        tail=NULL;
        count=0;
    }
    
    int get(int index) 
    {
        if(index<0 or index>=count or head==NULL)
        return -1;
        Node* temp = head;
        int ind = 0;
        int ans=-1;
        while(temp!=NULL)
        {
            if(ind==index)
            {
                ans = temp->val;
                break;
            }
            temp = temp->next;
            ind++;
        }
        return ans;
    }
    
    void addAtHead(int val) 
    {
        Node* node = new Node(val);
        if(head==NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev=node;
            node->next=head;
            head=node;
        }
        count = count + 1;
    }
    
    void addAtTail(int val) 
    {
        Node* node = new Node(val);
        if(head==NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
        count = count + 1;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index<0 or index>count)
        return;
        else if(index==0)
        addAtHead(val);
        else if(index==count)
        addAtTail(val);
        else
        {
            int ind=0;
            Node* node = new Node(val);
            Node* temp = head;
            while(temp!=NULL)
            {
                if(ind==index)
                {
                    Node* prev_node = temp->prev;
                    prev_node->next = node;
                    temp->prev=node;
                    node->prev=prev_node;
                    node->next=temp;
                }
                temp = temp->next;
                ind++;
            }
            count = count + 1;
        }
        
    }

    void deleteAtHead()
    {
        if(head!=NULL)
        {
            Node* temp = head;
            if(count==1)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                head = head->next;
                head->prev=NULL;
            }
            delete temp;
            count = count - 1;
        }
    }
    
    void deleteAtTail()
    {
        if(tail!=NULL)
        {
            Node* temp = tail;
            if(count == 1)
            {
                tail=NULL;
                head=NULL;
            }
            else
            {
                tail = tail->prev;
                tail->next=NULL;
            }
            delete temp;
            count = count - 1;
        }

    }
    void deleteAtIndex(int index) 
    {
        if(index<0 or index>=count or head==NULL)
        return;
        else if(index==0)
        deleteAtHead();
        else if(index==count-1)
        deleteAtTail();
        else
        {
            int ind=0;
            Node* temp = head;
            while(temp!=NULL)
            {
                if(ind==index)
                {
                    Node* current_node = temp;
                    Node* prev_node = temp->prev;
                    Node* next_node = temp->next;
                    prev_node->next = next_node;
                    next_node->prev = prev_node;
                    delete current_node;
                    break;
                }
                temp = temp->next;
                ind++;
            }
            count = count - 1;
        }
    }
};
