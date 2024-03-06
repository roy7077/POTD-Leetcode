// Time complexity- O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool hasCycle(ListNode *head) {
        if(!head)
        return 0;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            return 1;
        }
        return 0;
    }
};