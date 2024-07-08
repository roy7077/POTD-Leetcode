// Time complexity - O(N*K)
// Space complexity- O(N)
class Node{
    public:
    int data;
    Node* next=NULL;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class Solution {
    public:
    int findTheWinner(int n, int k) {
        
        // making circular linked list
        Node* head=NULL;
        Node* tail=NULL;
        
        for(int i=1;i<=n;i++)
        {
            Node* newnode=new Node(i);
            if(!head)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
        }
        
        tail->next=head;
        
        // the actual calculation
        Node* prev=tail;
        Node* h=head;
        
        if(tail==head)
        return head->data;
        
        while(h->next)
        {
            int cnt=k;
            while(cnt>=1)
            {
                if(cnt==1)
                {
                    prev->next=h->next;
                    delete h;
                    h=prev->next;
                    
                    if(prev==h)
                    return prev->data;
                    
                    break;
                }
                
                cnt--;
                prev=h;
                h=h->next;
            }
        }
        
        return h->data;
    }
};