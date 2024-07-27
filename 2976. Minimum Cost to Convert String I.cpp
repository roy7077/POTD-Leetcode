class Solution {
    public:
    //dij algorithm to find minimum distance from particular character to each character
    vector<long long> solve(int a,vector<pair<int,int>>adj[]) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,a});
        vector<long long>dist(26,-1);
        while(!q.empty()) {
            pair<long long,int>p=q.top();
            q.pop();
            for(auto i:adj[p.second]) {
                if(dist[i.first]==-1 || p.first+i.second<dist[i.first]) {
                    dist[i.first]=p.first+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        return dist;
    }
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        
        //making adj list
        vector<pair<int,int>>adj[30];
        int n=o.size();
        for(int i=0;i<n;i++) {
            adj[o[i]-'a'].push_back({c[i]-'a',cost[i]});
        }
        
        //shortest distance from specific character to each character and storing into map
        map<int,vector<long long>>m;
        for(int i=0;i<26;i++) {
            vector<long long>k=solve(i,adj);
            m[i]=(k);
        }
        
        //calculating ans
        n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++) {
            if(s[i]!=t[i]) {
                long long k=m[s[i]-'a'][t[i]-'a'];
                if(k==-1)
                    return -1;
                ans=ans+k;
            }
        }
        return ans;
    }
};
