
/* Method - 1
   Time complexity - O(N)
   Space complexity- O(1)
*/
class Solution {
    public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int zero=0;
        for(auto it:s)
        {
            if(it=='1')
            one++;
            else
            zero++;
        }
        
        for(auto& it:s)
        {
            if(one>1)
            {
                it='1';
                one--;
            }
            else if(zero>=0)
            {
                it='0';
                zero--;
            }
        }
        s[s.length()-1]='1';
        return s;
    }
};

/* Method - 2
   Time complexity - O(N)
   Space complexity- O(1)
*/
class Solution {
    public:
    string maximumOddBinaryNumber(string s) {
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(s[j]=='1')
            {
                swap(s[i],s[j]);
                i++;
            }
            j++;
        }
        if(s[j-1]=='1')
        return s;
        
        s[i-1]='0';
        s[j-1]='1';
        return s;
    }
};