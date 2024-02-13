// CPP
class Solution {
    public:
    bool help(string& s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return 0;
            
            i++;
            j--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it:words)
        {
            if(help(it))
            return it;
        }
        return "";
    }
};
// JAVA
class Solution {
     static boolean help(String s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<j)
        {
            if(s.charAt(i)!=s.charAt(j))
            return false;
            
            i++;
            j--;
        }
        return true;
    }
    public String firstPalindrome(String[] words) {
        for(int i=0;i<words.length;i++)
        {
            if(help(words[i]))
            return words[i];
        }
        return "";
    }
}
// JAVASCRIPT
// Time complexity - O(N)
// Space complexity- O(1)
var fun=(string)=>{
    let i=0;
    let j=string.length-1;
    while(i<j)
    {
        if(string[i]!=string[j])
        return 0;
        
        i++;
        j--;
    }
    return 1;
}
var firstPalindrome = function(words) {
    for(let i=0;i<words.length;i++)
    {
        if(fun(words[i])===1)
        return words[i];
    }
    return "";
};