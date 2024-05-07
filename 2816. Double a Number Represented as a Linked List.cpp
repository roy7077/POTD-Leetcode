// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    string doubleString(string& s)
    {
        int carry=0;
        string ans="";
        int i=s.length()-1;
        while(i>=0)
        {
            int mul=2*(s[i]-'0')+carry;
            carry=mul/10;
            ans=char((mul%10)+48)+ans;
            i--;
        }
        if(carry)
        ans=char(carry+48)+ans;
        
        return ans;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=head;
        string num="";
        while(temp)
        {
            num+=char((temp->val)+48);
            temp=temp->next;
        }
        
        num=doubleString(num);
        temp=head;
        ListNode* pre=NULL;
        int i=0;
        while(i<num.length())
        {
            if(temp)
            {
                temp->val=num[i]-'0';
                pre=temp;
                temp=temp->next;
            }
            else
            {
                ListNode* newNode=new ListNode(num[i]-'0');
                pre->next=newNode;
                pre=newNode;
            }
            i++;
        }
        return head;
    }
};


// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* pre=NULL;
        while(temp)
        {
            ListNode* nextNode=temp->next;
            temp->next=pre;
            pre=temp;
            temp=nextNode;
        }
        return pre;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* rev=reverseList(head);
        ListNode* temp=rev;
        ListNode* pre=NULL;
        int carry=0;
        while(rev)
        {
            int num=2*(rev->val)+carry;
            carry=num/10;
            rev->val=num%10;
            pre=rev;
            rev=rev->next;
        }
        
        if(carry)
        {
            ListNode* newNode=new ListNode(carry);
            pre->next=newNode;
        }
        
        rev=reverseList(temp);
        return rev;
    }
};