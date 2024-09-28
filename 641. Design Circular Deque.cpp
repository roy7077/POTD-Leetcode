class Node{
    public:
    int data;
    Node* next=NULL;
    Node* prev=NULL;
    
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class MyCircularDeque {
    public:
    int size;
    int i;
    Node* head=NULL;
    Node* tail=NULL;
    
    MyCircularDeque(int k) {
        this->size=k;
        this->head=NULL;
        this->tail=NULL;
        this->i=0;
    }
    
    bool insertFront(int value) {
        
        if(i==size)
        return 0;
        
        Node* newNode=new Node(value);
        
        if(!head)
        {
            head=newNode;
            tail=newNode;
            head->prev=head;
            head->next=head;
        }
        else
        {
            newNode->next=head;
            newNode->prev=head->prev;
            head->prev->next=newNode;
            head->prev=newNode;
            head=newNode;
        }
        
        i++;
        return 1;
    }
    
    bool insertLast(int value) {
        
        if(i==size)
        return 0;
        
        Node* newNode=new Node(value);
        if(!head)
        {
            head=newNode;
            tail=newNode;
            head->prev=head;
            head->next=head;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head->prev=newNode;
            tail=newNode;
        }
        
        i++;
        return 1;
    }
    
    bool deleteFront() {
        
        if(i==0)
        return 0;
        
        if(i==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            i--;
            return 1;
        }
        
        Node* prevNode=head->prev;
        Node* nextNode=head->next;
        
        delete head;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
        head=nextNode;
        i--;
        return 1;
    }
    
    bool deleteLast() {
        if(i==0)
        return 0;
        
        if(i==1)
        {
            delete head;
            head=NULL;
            tail=NULL;
            i--;
            return 1;
        }
        
        Node* prevNode=tail->prev;
        
        delete tail;
        prevNode->next=head;
        head->prev=prevNode;
        tail=prevNode;
        i--;
        return 1;
    }
    
    int getFront() {
        
        if(i==0)
        return -1;
        
        return head->data;
    }
    
    int getRear() {
        
        if(i==0)
        return -1;
        
        return tail->data;
    }
    
    bool isEmpty() {
        return i==0;
    }
    
    bool isFull() {
        return i==size;
    }
};
