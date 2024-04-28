/*
 Very important concept
 Shifting the root
*/
class Solution {
    public:
    vector<int> cntNode;
    int N=0;
    int firstDfs(vector<int>* adj,int node,int parent,int tempSum,int& totalSum)
    {
        totalSum+=tempSum;
        int countNode=1;
        for(auto& it:adj[node])
        {
            if(it==parent)
            continue;
            
            countNode+=firstDfs(adj,it,node,tempSum+1,totalSum);
        }
        cntNode[node]=countNode;
        return countNode;
    }
    
    void secondDfs(vector<int>* adj,int node,int parent,vector<int>& nodeSum)
    {
        for(auto& it:adj[node])
        {
            if(it==parent)
            continue;
            
            nodeSum[it]=nodeSum[node]-cntNode[it]+(N-cntNode[it]);
            secondDfs(adj,it,node,nodeSum);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        //making adj list
        vector<int> adj[n];
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //the actual solution
        N=n;
        cntNode.resize(n,0);
        vector<int> nodeSum(n,0);
        int sum=0;
        firstDfs(adj,0,-1,0,sum);
        nodeSum[0]=sum;
        
        //call second dfs to calculate for remaining node
        secondDfs(adj,0,-1,nodeSum);
        
        return nodeSum;
    }
};
