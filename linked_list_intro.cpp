#include<bits/stdc++.h>
#include<iostream>
#define ll long long int 
using namespace std;

class Node
{
    public:
    ll data;
    Node* next;
    Node(ll data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linked_List
{
    public:
    Node* head;
    Linked_List()
    {
        this->head = NULL;
    }
    
    void add(ll data)
    {
        Node* node = new Node(data);
        if(this->head == NULL)
        this->head = node;
        else
        {
            Node* temp = this->head;
            while(temp->next!=NULL)
            temp = temp->next;
            temp->next = node;
        }
    }
    void print()
    {
        if(this->head == NULL)
        {
            cout<<"Linked_List is Empty"<<endl;
            return;
        }
        else
        {
            Node* temp = this->head;
            cout<<"Linked list is :";
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        cout<<endl;
    }
    Node* middle_node()
    {
        if(this->head == NULL)
        return head;
        else
        {
            // slower pointer :- 1->2->3->4->5....
            // fast pointer :- 1->3->5->7->9.....
            // no. of elements can be odd or even. if the no. of elements is odd then 
            // fp->next becomes NULL and be if its even then fp becomes NULL 
            Node* fp = this->head;
            Node* sp = this->head;
            while(fp != NULL and fp->next != NULL)
            {
                sp = sp->next;
                fp = fp->next->next;
            }
            return sp;
        }
    }
    void delete_middle_node()
    {
        //we need one more pointer called pre apart from sp and fp. It points to sp previous element 
        if(this->head == NULL)
        return;
        else
        {
            Node* sp = this->head;
            Node* fp = this->head;
            Node* pre = this->head; //previous pointer of sp 
            while(fp!=NULL and fp->next!=NULL)
            {
                pre = sp;
                sp = sp->next;
                fp = fp->next->next;
            }
            pre->next = sp->next;
            delete sp;
            return;
        }
    }
};


int main()
{
    Linked_List l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.add(5);
    l1.print();
    // l1 = 1,2,3,4,5
    Node* middle_node = l1.middle_node();
    if(middle_node != NULL)
    cout<<"The middle element is :"<<middle_node->data<<endl;
    l1.add(6);
    // l1 = 1,2,3,4,5,6 
    middle_node = l1.middle_node();
    if(middle_node != NULL)
    cout<<"The middle element is :"<<middle_node->data<<endl;
}
