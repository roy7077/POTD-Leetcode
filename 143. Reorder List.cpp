// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    void reorderList(ListNode* head) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        while(temp)
        {
            ans.push_back(temp);
            temp=temp->next;
        }
        
        int i=0;
        int j=ans.size()-1;
        bool flag=1;
        ListNode* ansH=NULL;
        ListNode* ansT=NULL;
        while(i<=j)
        {
            if(flag)
            {
                if(!ansH)
                {
                    ansH=ans[i];
                    ansT=ans[i];
                }
                else
                {
                    ansT->next=ans[i];
                    ansT=ans[i];
                }
                i++;
            }
            else
            {
                if(!ansH)
                {
                    ansH=ans[j];
                    ansT=ans[j];
                }
                else
                {
                    ansT->next=ans[j];
                    ansT=ans[j];
                }
                j--;
            }
            flag=(!flag);
        }
        ansT->next=NULL;
    }
};