class Node
{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key,int value)
        {   
            this->key = key;
            this->value = value;
            this->prev = NULL;
            this->next = NULL;
        }
};


class DoublyLinkedList
{
    public:
        Node* tail;
        Node* head;
        DoublyLinkedList()
        {
            tail=NULL;
            head=NULL;
        }
        bool isEmpty()
        {
            return head == NULL;
        }
        void deleteTailNode()
        {
            if(head==NULL)
            return;
            else if(head==tail)
            {
                Node* temp = tail;
                head=NULL;
                tail=NULL;
                delete temp;
            }
            else
            {
                Node* temp = tail;
                tail=tail->prev;
                tail->next=NULL;
                delete temp;
            }
        }
        void insertAtHead(Node* node)
        {
            if(head==NULL)
            {
                head=node;
                tail=node;
            }
            else
            {
                node->next=head;
                head->prev=node;
                head=node;
            }
        }
        void removeHeadNode()
        {
            // remove means just to disconnect and not to delete the node.
            if(head==NULL)
            return;
            else if(head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                Node* temp = head;
                head = head->next;
                temp->next=NULL;
                head->prev=NULL;
            }
        }
        void removeTailNode()
        {
            if(tail==NULL)
            return;
            else if(head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            else
            {
                Node* temp = tail;
                tail=tail->prev;
                tail->next=NULL;
                temp->prev=NULL;
            }
        }
        void removeNode(Node* temp)
        {
            if(head==NULL or temp==NULL)
            return;
            else if(temp==head)
            removeHeadNode();
            else if(temp==tail)
            removeTailNode();
            else
            {
                Node* prev_node = temp->prev;
                Node* next_node = temp->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                temp->prev=NULL;
                temp->next=NULL;
            }
        }
        Node* getTailNode()
        {
            return tail;
        }
};








class LRUCache 
{
    int max_capacity;
    int current_capacity;
    DoublyLinkedList* dl;
    unordered_map<int,Node*> mp;
public:
    LRUCache(int capacity) 
    {
        this->max_capacity=capacity;
        this->current_capacity=0;
        this->dl = new DoublyLinkedList();
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            Node* node = mp[key];
            int value = node->value;
            dl->removeNode(node);
            dl->insertAtHead(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            Node* node = mp[key];
            node->value = value;
            dl->removeNode(node);
            dl->insertAtHead(node);
        }
        else
        {
            Node* node = new Node(key,value);
            if(current_capacity<max_capacity)
            {
                dl->insertAtHead(node);
                current_capacity++;
            }
            else
            {
                Node* tail = dl->getTailNode();
                dl->removeTailNode();
                mp.erase(tail->key);
                dl->insertAtHead(node);
            }
            mp[key]=node;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
