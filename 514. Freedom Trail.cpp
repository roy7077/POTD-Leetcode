// Memoization
class Solution {
    public:
    int help(string& ring,string& key,int i,int ind,vector<vector<int>>& memo)
    {
        //base case
        if(ind>=key.length())
        return 0;
        
        //memo check
        if(memo[i][ind]!=-1)
        return memo[i][ind];
        
        //recursive calls
        //and small calculation
        char it=key[ind];
        int j=i;
        bool isFound1=0;
        int cnt1=0;
        while(j<ring.length())
        {
            if(ring[j]==it)
            {
                isFound1=1;
                break;
            }
            cnt1++;
            j++;
        }

        if(!isFound1)
        j=0;

        while(!isFound1 and j<ring.length())
        {
            if(ring[j]==it)
            break;

            cnt1++;
            j++;
        }

        //Clockwise
        int k=i;
        int cnt2=0;
        bool isFound2=0;
        while(k>=0)
        {
            if(ring[k]==it)
            {
                isFound2=1;
                break;
            }
            cnt2++;
            k--;
        }

        if(!isFound2)
        k=ring.length()-1;

        while(!isFound2 and k>=0)
        {
            if(ring[k]==it)
            break;

            cnt2++;
            k--;
        }

        int a=cnt1+1+help(ring,key,j,ind+1,memo);
        int b=cnt2+1+help(ring,key,k,ind+1,memo);

        return memo[i][ind]=min(a,b);
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.length();
        int m=key.length();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return help(ring,key,0,0,memo);
    }
};

// Tabulation
class Solution {
    public:
    int findRotateSteps(string ring, string key) {
        int m=ring.length();
        int n=key.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            char it=key[ind];
            for(int i=0;i<m;i++)
            {
                // Anticlock wise
                int j=i;
                bool isFound1=0;
                int cnt1=0;
                while(j<ring.length())
                {
                    if(ring[j]==it)
                    {
                        isFound1=1;
                        break;
                    }
                    cnt1++;
                    j++;
                }

                if(!isFound1)
                j=0;

                while(!isFound1 and j<ring.length())
                {
                    if(ring[j]==it)
                    break;

                    cnt1++;
                    j++;
                }

                //Clockwise
                int k=i;
                int cnt2=0;
                bool isFound2=0;
                while(k>=0)
                {
                    if(ring[k]==it)
                    {
                        isFound2=1;
                        break;
                    }
                    cnt2++;
                    k--;
                }

                if(!isFound2)
                k=ring.length()-1;

                while(!isFound2 and k>=0)
                {
                    if(ring[k]==it)
                    break;

                    cnt2++;
                    k--;
                }

                int a=cnt1+1;
                int b=cnt2+1;
                if(ind+1<n)
                {
                    a+=dp[ind+1][j];
                    b+=dp[ind+1][k];
                }
                
                dp[ind][i]=min(a,b);
            }
        }
        return dp[0][0];
    }
};

// Space optimized
class Solution {
    public:
    int findRotateSteps(string ring, string key) {
        int m=ring.length();
        int n=key.length();
        vector<int> next(m,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            char it=key[ind];
            vector<int> curr(m,0);
            for(int i=0;i<m;i++)
            {
                // Anticlock wise
                int j=i;
                bool isFound1=0;
                int cnt1=0;
                while(j<ring.length())
                {
                    if(ring[j]==it)
                    {
                        isFound1=1;
                        break;
                    }
                    cnt1++;
                    j++;
                }

                if(!isFound1)
                j=0;

                while(!isFound1 and j<ring.length())
                {
                    if(ring[j]==it)
                    break;

                    cnt1++;
                    j++;
                }

                //Clockwise
                int k=i;
                int cnt2=0;
                bool isFound2=0;
                while(k>=0)
                {
                    if(ring[k]==it)
                    {
                        isFound2=1;
                        break;
                    }
                    cnt2++;
                    k--;
                }

                if(!isFound2)
                k=ring.length()-1;

                while(!isFound2 and k>=0)
                {
                    if(ring[k]==it)
                    break;

                    cnt2++;
                    k--;
                }

                int a=cnt1+1;
                int b=cnt2+1;
                if(ind+1<n)
                {
                    a+=next[j];
                    b+=next[k];
                }
                
                curr[i]=min(a,b);
            }
            next=curr;
        }
        return next[0];
    }
};