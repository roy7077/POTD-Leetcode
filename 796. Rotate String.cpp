class Solution {
    public:
    bool rotateString(string s, string goal) {
        // base case
        if(s==goal)
        return 1;

        for(int i=0;i<s.length();i++)
        {
            char ch=s[0];
            s.erase(s.begin());
            s+=ch;
            
            if(s==goal)
            return 1;
        }
        return 0;
    }
};
