class Solution {
    public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int i=0;
        int j=0;
        
        while(i<n and j<m)
        {
            if(str1[i]==str2[j] or ((char((str1[i]-'a'+1)%26)+'a'))==str2[j])
            j++;
            
            i++;
        }
        
        return j>=m;
    }
};
