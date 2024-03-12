
// Method - 1
// Time complexity - O(NlogN)
// Space complexity- O(N+N)
typedef pair<int,ListNode*> pi;
class Solution {
    public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        // finding subarrays with sum 0 and deleting them
        unordered_map<int,pi> mp;
        int i=0;
        int sum=0;
        ListNode* h1=head;
        while(h1)
        {
            sum+=h1->val;
            cout<<sum<<endl;
            if(mp.count(sum) or sum==0)
            {
                int ind;
                if(sum==0)
                ind=0;
                else
                ind=mp[sum].first+1;
                auto it=mp.begin();
                while(it!=mp.end())
                {
                    if(it->second.first>=ind and it->second.first<=i)
                    it=mp.erase(it);
                    else
                    it++;
                }
            }
            else
            mp[sum]={i,h1};

            h1=h1->next;
            i++;
        }
        
        // making linkedlist out the array
        vector<pi> v;
        for(auto it:mp)
        v.push_back({it.second.first,it.second.second});
        
        sort(v.begin(),v.end(),[](pi& a,pi& b){
            return a.first<=b.first;
        });
        
        ListNode* resH=NULL;
        ListNode* resT=NULL;
        for(auto it:v)
        {
            if(resH==NULL)
            {
                resH=it.second;
                resT=it.second;
            }
            else
            {
                resT->next=it.second;
                resT=it.second;
            }
        }
        
        if(resT)
        resT->next=NULL;
        
        return resH;
    }
};


// Method - 2
// Time complexity - O(N)
// Space complexity- O(N)

class Solution {
    public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode *dummy = new ListNode(0);
        ListNode* h=head;
        dummy->next = head;
        mp[0] = dummy;
        int sum=0;
        while(h)
        {
            sum += h->val;
            if(mp.find(sum) != mp.end())
            {
                //delete the node
                ListNode *start = mp[sum];
                ListNode *temp = start;
                int pSum = sum;
                while(temp != h)
                {
                    temp = temp->next;
                    pSum += temp->val;
                    if(temp != h)
                    mp.erase(pSum);
                }
                start->next = h->next;
            }
            else
            mp[sum] = h;
            
            h=h->next;
        }
        
        return dummy->next;
    }
};