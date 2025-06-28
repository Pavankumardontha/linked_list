class Node
{
    public:
    string val;
    Node* next;
    Node* prev;
    Node(string x)
    {
        this->val=x;
        this->next=NULL;
        this->prev=NULL;
    }
};

class DoublyLinkedList
{
    Node* head;
    Node* current; // current page of the user
    public:
    DoublyLinkedList()
    {
        this->head=NULL;
        this->current=NULL;
    }
    void add(string val)
    {
        Node* temp = new Node(val);
        if(current==NULL)
        {
            head = temp;
            current = head;
        }
        else
        {
            current->next=temp;
            temp->prev=current;
            current=temp; 
        }
    }
    string back(int steps)
    {
        int i=0;
        while(current->prev != NULL and i<steps)
        {
            current=current->prev;
            i++;
        }
        return current->val;
    }
    string forward(int steps)
    {
        int i=0;
        while(current->next != NULL and i<steps)
        {
            current = current->next;
            i++;
        }
        return current->val;
    }
};

class BrowserHistory {
DoublyLinkedList* dll;
public:
    BrowserHistory(string homepage) 
    {
        dll = new DoublyLinkedList();
        dll->add(homepage);
    }
    
    void visit(string url) 
    {
        dll->add(url);
    }
    
    string back(int steps) 
    {
        return dll->back(steps);
    }
    
    string forward(int steps) 
    {
        return dll->forward(steps);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
