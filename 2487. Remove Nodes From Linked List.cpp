// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* h=head;
        
        while(h)
        {
            ListNode* nextNode=h->next;
            h->next=pre;
            pre=h;
            h=nextNode;
        }
        return pre;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* rev=reverseList(head);
        ListNode* temp=rev;
        ListNode* pre=NULL;
        int maxi=-1;
        while(temp)
        {
            if(temp->val<maxi)
            {
                ListNode* nextNode=temp->next;
                delete temp;
                pre->next=nextNode;
                temp=nextNode;
            }
            else
            {
                maxi=temp->val;
                pre=temp;
                temp=temp->next;
            }
        }
        rev=reverseList(rev);
        return rev;
    }
};