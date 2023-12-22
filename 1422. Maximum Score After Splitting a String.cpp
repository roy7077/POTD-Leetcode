// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxScore(string s) {
        int one=0;
        for(auto it:s)
        {
            if(it=='1')
            one++;
        }
        
        int maxi=0;
        int zero=0;
        for(int i=0;i<s.length()-1;i++)
        {
            char it=s[i];
            if(it=='1')
            one--;
            else
            zero++;
            
            maxi=max(maxi,one+zero);
        }
        
        return maxi;
    }
};

