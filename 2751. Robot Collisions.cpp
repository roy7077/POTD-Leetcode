// Time complexity - O(NlogN)
// Space complexity- O(N*3+N+N)
class Solution {
    public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]<b[0])
        return 1;
        else
        return 0;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector<vector<int>> v;
        int n=positions.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({positions[i],healths[i]});
            if(directions[i]=='L')
            v[i].push_back(0);
            else
            v[i].push_back(1);
        }
        
        //sorting
        sort(v.begin(),v.end(),cmp);
        
        unordered_map<int,int> mp;
        for(int i=0;i<v.size();i++)
        mp[v[i][0]]=i;
        
        vector<int> indexes(v.size());
        for(int i=0;i<n;i++)
        indexes[i]=mp[positions[i]];
        
        // solution
        stack<int> st;
        for(int i=0;i<v.size();i++)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            else if(v[i][2]==1)
            {
                st.push(i);
                continue;
            }
            
            while(!st.empty())
            {
                int top=st.top();
                if(v[top][2]==1)
                {
                    if(v[top][1]>v[i][1])
                    {
                        v[top][1]--;
                        v[i][1]=0;
                        
                        if(v[top][1]==0)
                        st.pop();
                        
                        break;
                    }
                    else if(v[i][1]>v[top][1])
                    {
                        v[top][1]=0;
                        st.pop();
                        v[i][1]--;
                        
                        if(v[i][1]==0)
                        break;
                    }
                    else
                    {
                        v[top][1]=0;
                        st.pop();
                        v[i][1]=0;
                        break;
                    }
                }
                else
                break;
            }
            
            if(v[i][1]!=0)
            st.push(i);
        }
        
        // ans
        vector<int> ans;
        for(auto& it:indexes)
        {
            if(v[it][1]!=0)
            ans.push_back(v[it][1]);
        }
        
        return ans;
    }
};
