// Method - 1 
// Time complexity - O(N)
// Space complexity- O(26) - constant
class Solution {
    public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        for(auto it:s)
        mp[it]++;
        
        int odd=0;
        int even=0;
        
        for(auto& it:mp)
        {
            even+=(it.second/2);
            odd+=(it.second%2);
        }
        
        return odd ? (2*even)+1 : (2*even);
    }
};



// Method - 2 
// Time complexity - O(NlogN)
// Space complexity- O(1) - constant
class Solution {
    public:
    int longestPalindrome(string s) {
        sort(s.begin(),s.end());
        int i=1;
        int cnt=1;
        int even=0;
        int odd=0;
        
        while(i<s.length())
        {
            if(s[i-1]==s[i])
            cnt++;
            else
            {
                even+=cnt/2;
                odd+=cnt%2;
                cnt=1;
            }
            i++;
        }
        
        even+=cnt/2;
        odd+=cnt%2;
        return odd ? (2*even)+1 : (2*even);
    }
};

