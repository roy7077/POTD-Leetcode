/*-----------BRUTE FORCE--------------*/
class Solution {
    public:
    int kthGrammar(int n, int k) {
        string ans="0";
        if(n==1)
        return (ans[k-1]-'0');
        
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=0;j<ans.length();j++)
            {
                if(ans[j]=='0')
                temp+="01";
                else
                temp+="10";
            }
            ans=temp;
        }
        
        return (ans[k-1]-'0');
    }
};

/*----------------OPTIMAL APPROACH-----------------*/
class Solution {
    public:
    int help(int n,int k)
    {
        //base case
        if(n==1)
        return 0;
        
        //recursive calls
        //small calculation
        int len=pow(2,n-1);
        if(k<=(len/2))
        return help(n-1,k);
        else
        return !help(n-1,k-(len/2));
    }
    
    int kthGrammar(int n, int k) {
        return help(n,k);
    }
};