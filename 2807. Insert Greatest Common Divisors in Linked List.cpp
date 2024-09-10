class Solution {
    public:
    int gcd(int a,int b)
    {
        int maxi=max(a,b);
        int mini=min(a,b);
        
        int i=mini;
        while(i!=0 and mini/i >=1)
        {
            if(mini%i==0 and maxi%i==0)
            return i;
            
            i--;
        }
        return 1;
    }
    
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;        
        while(temp->next)
        {
            int a=temp->val;
            int b=temp->next->val;
            
            int gcdValue=gcd(a,b);
            
            ListNode* nextNode=temp->next;
            ListNode* newNode=new ListNode(gcdValue);
            temp->next=newNode;
            newNode->next=nextNode;
            temp=nextNode;
        }
        
        return head;
    }
};

