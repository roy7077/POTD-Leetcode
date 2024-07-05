// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int mini=1e9;
        int maxi=-1e9;
        
        ListNode* prev=NULL;
        ListNode* h=head;
        
        int prevInd=-1;
        int firstInd=-1;
        
        int i=1;
        while(h)
        {
            if(prev and h->next)
            {
                if(((h->val)>(prev->val) and (h->val)>(h->next->val)) or ((h->val)<(prev->val) and (h->val)<(h->next->val)))
                {
                    if(firstInd==-1)
                    {
                        firstInd=i;
                        prevInd=i;
                    }
                    else
                    {
                        mini=min(mini,i-prevInd);
                        prevInd=i;
                    }
                }
                
            }
            prev=h;
            h=h->next;
            i++;
        }
        
        maxi=prevInd-firstInd;
        
        if(mini>=1e9)
        return {-1,-1};
        
        return {mini,maxi};
    }
};