
/* Method - 1
   Recusion
   Time complexity - O(N)
   Space complexity- O(N -> Recursion call stack)
*/
class Solution {
    public:
    ListNode* help(ListNode* head,int n,int& pos)
    {
        //base case
        if(!head)
        {
            pos=0;
            return NULL;
        }
        
        //Recursive calls
        //and small calculation
        ListNode* temp=help(head->next,n,pos);
        head->next=temp;
        
        pos++;
        
        if(pos==n)
        {
            ListNode* NextNode=head->next;
            delete head;
            return NextNode;
        }
        
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos=0;
        ListNode* node=help(head,n,pos);
        return node;
    }
};

/* Method - 2
   Iterative
   Time complexity - O(N)
   Space complexity- O(1)
*/
class Solution {
    public:
    int length(ListNode* head)
    {
        int cnt=0;
        while(head)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=length(head);
        int pos=len-n+1;
        int i=0;
        
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(1)
        {
            i++;
            if(i==pos)
            {
                if(i==1)
                {
                    ListNode* NextNode=curr->next;
                    delete curr;
                    return NextNode;
                }
                else
                {
                    ListNode* NextNode=curr->next;
                    delete curr;
                    pre->next=NextNode;
                    break;
                }
            }
            pre=curr;
            curr=curr->next;
        }
        return head;
    }
};