// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st;
        for(auto& it:nums)
        st.insert(it);
        
        ListNode* h=NULL;
        ListNode* t=NULL;
    
        while(head)
        {
            if(st.count(head->val))
            {
                ListNode* nextNode=head->next;
                delete head;
                head=nextNode;
                continue;
            }
            
            if(!h)
            {
                h=head;
                t=head;
            }
            else
            {
                t->next=head;
                t=head;
            }
            head=head->next;
        }
        
        if(t)
        t->next=NULL;
        
        return h;
    }
};
