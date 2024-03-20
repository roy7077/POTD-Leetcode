// Iterative 
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        //finding the first and last node
        ListNode* nodeF=list2;
        ListNode* nodeL=NULL;
        while(list2)
        {
            nodeL=list2;
            list2=list2->next;
        }
        
        //deletion and insertion
        ListNode* head=list1;
        ListNode* node1=NULL;
        ListNode* node2=NULL;
        int pos=0;
        while(head)
        {
            if(pos==a-1)
            node1=head;
            else if(pos==b+1)
            {
                node2=head;
                break;
            }
            
            head=head->next;
            pos++;
        }
        
        node1->next=nodeF;
        nodeL->next=node2;
        return list1;
    }
};


// Recursion
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    ListNode* help(ListNode* list1,int pos,int a,int b,ListNode* nodeF,ListNode* nodeL)
    {
        //base case
        if(!list1)
        return NULL;
        
        //recursive calls
        //and small calculation
        ListNode* temp=help(list1->next,pos+1,a,b,nodeF,nodeL);
        if(pos>a and pos<b)
        {
            delete list1;
            return temp;
        }
        
        if(pos==a and pos==b)
        {
            nodeL->next=temp;
            return nodeF;
        }
        else if(pos==a)
        return nodeF;
        else if(pos==b)
        {
            nodeL->next=temp;
            delete list1;
            return nodeL;
        }
        
        list1->next=temp;
        return list1;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        //finding the first and last node
        ListNode* nodeF=list2;
        ListNode* nodeL=NULL;
        while(list2)
        {
            nodeL=list2;
            list2=list2->next;
        }
        
        //inserting list2 in between list1
        return help(list1,0,a,b,nodeF,nodeL);
    }
};