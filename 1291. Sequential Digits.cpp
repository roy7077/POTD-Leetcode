
// Recursion
class Solution {
    public:
    void help(int num,int& low,int& high,vector<int>& ans,unordered_map<int,int>& mp)
    {
        //base case
        if(num>high)
        return ;
        
        if(num>=low and num<=high)
        ans.push_back(num);
        
        //recursive calls
        //and small calculation
        for(int i=0;i<=9;i++)
        {
            if(num==-1)
            {
                if(i==0)
                continue;
                
                mp[i]++;
                help(i,low,high,ans,mp);
            }
            else
            {
                if((i-1)==(num%10))
                {
                    int temp=(num*10)+i;
                    if(mp[temp]>=1)
                    continue;
                    
                    mp[temp]++;
                    help(temp,low,high,ans,mp);
                }
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        help(-1,low,high,ans,mp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// ITERATIVE
class Solution {
    public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        
        for(int i=0;i<=9;i++)
        q.push(i);
            
        vector<int> ans;
        unordered_map<int,int> visited;
        while(!q.empty())
        {
            int num=q.front();
            q.pop();
            
            for(int i=0;i<=9;i++)
            {
                int temp=num;
                if((i-1)==(temp%10))
                {
                    temp=(temp*10)+i;
                    if(visited[temp]==0)
                    {
                        if(temp>high)
                        continue;
                        
                        visited[temp]++;
                        q.push(temp);
                        if(temp>=low and temp<=high)
                        ans.push_back(temp);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};