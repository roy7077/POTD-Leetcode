/* Method - 1
   Store frequency
   Time complexity - O(N)
   Space complexity- O(26)
*/
class Solution {
    public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(auto it:s)
        freq[it-'a']++;
        
        for(int i=0;i<s.length();i++)
        {
            if(freq[s[i]-'a']==1)
            return i;
        }
        return -1;
    }
};


/* Method - 2
   Store indexes
   Time complexity - O(N)
   Space complexity- O(26)
*/
class Solution {
    public:
    int firstUniqChar(string s) {
        vector<int> index(26,0);
        for(int i=0;i<s.length();i++)
        index[s[i]-'a']=i;
        
        for(int i=0;i<s.length();i++)
        {
            if(index[s[i]-'a']==i)
            return i;
            else
            index[s[i]-'a']=i;
        }
        return -1;
    }
};