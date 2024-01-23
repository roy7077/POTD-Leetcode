// RECURSION
// Time complexity - O(2^N * length of string)
// Space complexity- (N+N+N)
class Solution {
    public:
    int help(vector<string>& arr,int i,string temp,unordered_map<char,int>& mp,vector<int>& unique)
    {
        //base case
        if(i==arr.size())
        return temp.length();
        
        //recursive calls
        //small calculation
        int a=help(arr,i+1,temp,mp,unique);
        
        bool flag=1;
        for(auto it:arr[i])
        {
            if(mp[it]>=1)
            {
                flag=0;
                break;
            }
        }
        
        int b=0;
        if(flag and unique[i])
        {
            for(auto it:arr[i])
            mp[it]++;
            
            b=help(arr,i+1,temp+arr[i],mp,unique);
            
            for(auto it:arr[i])
            mp[it]--;
        }
        
        return max(a,b);
        
    }
    int maxLength(vector<string>& arr) {
        
        vector<int> unique(arr.size(),1);
        for(int i=0;i<arr.size();i++)
        {
            unordered_map<char,int> mp;
            bool flag=1;
            for(auto x:arr[i])
            {
                if(mp.count(x))
                {
                    flag=0;
                    break;
                }
                
                mp[x]++;
            }
            
            if(flag)
            unique[i]=1;
            else
            unique[i]=0;
        }
        
        unordered_map<char,int> mp;
        string ans="";
        
        return help(arr,0,"",mp,unique);
    }
};


// Powerset
// Time complexity - O(2^N * N * length of string)
// Space complexity- (N+N)
class Solution {
    public:
    int maxLength(vector<string>& arr) {
        
        vector<int> unique(arr.size(),1);
        for(int i=0;i<arr.size();i++)
        {
            unordered_map<char,int> mp;
            bool flag=1;
            for(auto x:arr[i])
            {
                if(mp.count(x))
                {
                    flag=0;
                    break;
                }
                
                mp[x]++;
            }
            
            if(flag)
            unique[i]=1;
            else
            unique[i]=0;
        }
        
        int ans=0;
        for(int i=0;i<(1<<arr.size());i++)
        {
            unordered_map<char,int> mp;
            string temp="";
            for(int j=0;j<arr.size();j++)
            {
                if((i&(1<<j)) and unique[j])
                {
                    bool flag=1;
                    for(auto it:arr[j])
                    {
                        if(mp[it]>=1)
                        {
                            flag=0;
                            break;
                        }
                    }
                    
                    if(flag)
                    {
                        for(auto it:arr[j])
                        mp[it]++;
                        
                        temp+=arr[j];
                    }
                }
            }
            
            if(temp.length()>ans)
            ans=temp.length();
        }
        
        return ans;
    }
};