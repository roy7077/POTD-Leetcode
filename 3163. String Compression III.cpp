class Solution {
    public:
    string compressedString(string word) {
        string ans="";
        int cnt=1;
        char ch=word[0];
        int i=1;
        while(i<word.length())
        {
            if(cnt>=9)
            {
                ans+=to_string(cnt);
                ans+=ch;
                cnt=1;
                ch=word[i];
                i++;
                continue;
            }
            
            if(word[i-1]==word[i])
            cnt++;
            else
            {
                ans+=to_string(cnt);
                ans+=ch;
                cnt=1;
                ch=word[i];
            }
            i++;
        }
        
        if(cnt)
        {
            ans+=to_string(cnt);
            ans+=ch;
        }
        
        return ans;
    }
};
