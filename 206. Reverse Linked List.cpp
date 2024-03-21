// Method - 1
// Recursion
// Time complexity - O(N)
// Space complexity- O(N) - call stack space
class Solution {
    public:
    ListNode* help(ListNode* head)
    {
        //base case
        if(!head)
        return head;
        
        if(!(head->next))
        return head;
        
        //recursive calls
        //small calculation
        ListNode* temp=help(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        return help(head);
    }
};


// Method - 2
// Iterative
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* temp=head;
        while(temp)
        {
            ListNode* nextNode=temp->next;
            temp->next=pre;
            pre=temp;
            temp=nextNode;
        }
        return pre;
    }
};