// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    
    // length of a linked list
    int length(ListNode* head)
    {
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    // main function
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=length(head);
        int part=len/k;
        int rem=len%k;
        
        vector<ListNode*> ans;
        ListNode* temp=head;
        for(int i=0;i<k;i++)
        {
            int tempLen=part;
            ListNode* h=NULL;
            ListNode* t=NULL;
            
            while(tempLen)
            {
                if(!h)
                {
                    h=temp;
                    t=temp;
                }
                else
                {
                    t->next=temp;
                    t=temp;
                }
                tempLen--;
                temp=temp->next;
            }
            
            if(rem)
            {
                if(!h)
                {
                    h=temp;
                    t=temp;
                }
                else
                {
                    t->next=temp;
                    t=temp;
                }
                temp=temp->next;
                rem--;
                
                t->next=NULL;
                ans.push_back(h);
                continue;
            }
            
            if(part)
            {
                t->next=NULL;
                ans.push_back(h);
            }
            else
            ans.push_back(NULL);
        }
        return ans;
    }
};
