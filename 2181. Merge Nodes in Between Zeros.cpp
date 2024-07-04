// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tempHead=head;
        ListNode* ansNode=head;
        ListNode* preNode=NULL;
        int cntTwo=0;
        int sum=0;
        while(head)
        {
            if(head->val==0)
            cntTwo++;
            
            if(cntTwo==2)
            {
                preNode=ansNode;
                ansNode->val=sum;
                ansNode=ansNode->next;
                sum=0;
                cntTwo=1;
            }
           
            sum+=head->val;
            head=head->next;
        }
        preNode->next=NULL;
        return tempHead;
    }
};