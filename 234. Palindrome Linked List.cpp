// Method - 1
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool help(vector<int>& temp)
    {
        int i=0;
        int j=temp.size()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
            return 0;
            
            i++;
            j--;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        return help(temp);
    }
};