class Solution {
    public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> adj1[k+1];
        vector<int> adj2[k+1];
        
        vector<int> indegreeRow(k+1,0);
        vector<int> indegreeCol(k+1,0);
        
        for(auto& it:rowConditions)
        {
            indegreeRow[it[1]]++;
            adj1[it[0]].push_back(it[1]);
        }
        
        for(auto& it:colConditions)
        {
            indegreeCol[it[1]]++;
            adj2[it[0]].push_back(it[1]);
        }
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        // topo sort for row
        stack<int> st;
        for(int i=1;i<indegreeRow.size();i++)
        {
            if(indegreeRow[i]==0)
            st.push(i);
        }
        
        int r=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            
            mp1[top]=r;
            for(auto& it:adj1[top])
            {
                indegreeRow[it]--;
                if(indegreeRow[it]==0)
                st.push(it);
            }
            
            r++;
        }
        
        if(mp1.size()<k)
        return {};
        
        // topo sort for col
        for(int i=1;i<indegreeCol.size();i++)
        {
            if(indegreeCol[i]==0)
            st.push(i);
        }
        
        int c=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            
            mp2[top]=c;
            for(auto& it:adj2[top])
            {
                indegreeCol[it]--;
                if(indegreeCol[it]==0)
                st.push(it);
            }
            
            c++;
        }
        
        if(mp2.size()<k)
        return {};
        
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++)
        ans[mp1[i]][mp2[i]]=i;
        
        return ans;
    }
};
